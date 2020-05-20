#include <SPI.h>

//  PIN
const int RESET_PIN = 3;
const int START_PIN = 4;
const int CS_PIN = 5;
const int DRDY_PIN = 6;
const int CLKSEL_PIN = 7;

//  Command Definitions, data sheet pg. 40
//  System Commands
const byte WAKEUP_CMD = 0x02;
const byte STANDBY_CMD = 0x04;
const byte RESET_CMD = 0x06;
const byte START_CMD = 0x08;
const byte STOP_CMD = 0x0A;

//  Data Read Commands
const byte RDATAC_CMD = 0x10;
const byte SDATAC_CMD = 0x11;
const byte RDATA_CMD = 0x11;

//  Register Read & Write
const byte PREG_CMD = 0x20;
const byte WREG_CMD = 0x40;

void setup() {
  Serial.begin(9600);
  //  SPI Set Up
  SPI.begin();
  //  data sheet pg.12 -> SPI setting: CPOL = 0, CPHA = 1
  //  https://en.wikipedia.org/wiki/Serial_Peripheral_Interface
  SPI.setDataMode(SPI_MODE1);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.setBitOrder(MSBFIRST);

  //  Pin Set Up
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, LOW);
  pinMode(START_PIN, OUTPUT);
  digitalWrite(START_PIN, LOW);
  pinMode(CS_PIN, OUTPUT);
  digitalWrite(CS_PIN, LOW);
  pinMode(DRDY_PIN, INPUT);
  //  Used to select internal or external clock
  //  Pull CLKSEL_PIN low if external clock signal is provided
  pinMode(CLKSEL_PIN, OUTPUT);
  digitalWrite(CLKSEL_PIN, LOW);
  delay(2000);

  //  TODO: All the timing can be improved.

  //  Use internal oscillator. It oscillates at 2.048 MHz.
  //  Tclk: 2.048 MHz
  digitalWrite(CLKSEL_PIN, HIGH);
  delay(100);

  digitalWrite(RESET_PIN, HIGH);
  //  wait for VCAP1 to settle to 1.1V
  delay(1000);

  //  RESET & wait 18 clock cycles
  SPI.transfer(RESET_CMD);
  delayMicroseconds(32);

  //  Device wakes up automatically at RDATAC (Read Data Continous) mode.
  //  Send SDATAC (Stop Data Continous) command in order to write to registers.
  SPI.transfer(SDATAC_CMD);
  delayMicroseconds(10);

  //  CONFIG1
  //  CLK_EN = 1 -> enable internal clock output
  //  DR = 110 -> fMOD/4096
  writeToRegister(0b10110110, 0x01);

  //CONFIG2 C0h
  writeToRegister(0b11000000, 0x02);
  delayMicroseconds(20);
  
  //  CONFIG3
  //  PDB_REFBUF = 1 -> use internal reference
  writeToRegister(0b11100000, 0x03);
  delay(1000);

  //  short channel 1 input
  writeToRegister(0b00000001, 0x05);
  //  short channel 2 input
  writeToRegister(0b00000001, 0x06);
  //  short channel 3 input
  writeToRegister(0b00000001, 0x07);
  //  short channel 4 input
  writeToRegister(0b00000001, 0x08);
  //  short channel 5 input
  writeToRegister(0b00000001, 0x09);
  //  short channel 6 input
  writeToRegister(0b00000001, 0x0A);
  //  short channel 7 input
  writeToRegister(0b00000001, 0x0B);
  //  short channel 8 input
  writeToRegister(0b00000001, 0x0C);
  //  generate test signal
  //  CONFIG2 INT_CAL = 1
//  SPI.transfer(0b01000010);
//  delayMicroseconds(2);
//  SPI.transfer(0b00000000);
//  delayMicroseconds(2);
//  SPI.transfer(0b11110011);
//  delayMicroseconds(20);

  //  START
  digitalWrite(START_PIN, HIGH);
}

void loop() {
  delay(500);
  Serial.println("------- DATA BEGIN -------");
  Serial.println("CONFIG1: ");
  readRegister(0x01);
  Serial.println("CONFIG2: ");
  readRegister(0x02);
  Serial.println("CONFIG3: ");
  readRegister(0x03);
  Serial.println("Channel 1: ");
  readRegister(0x05);
  Serial.println("------- DATA END -------");
  delay(500);
}

//  Read every bit including leading zero
void readByteFull(byte byteOfData) {
  for (byte i = 0; i < 8; i++) {
    Serial.print(bitRead(byteOfData, 7 - i));
  }
  Serial.print("\n");
}

byte writeToRegister(byte command, byte address) {
  byte _address = WREG_CMD | address;
  
  Serial.println("address: ");
  readByteFull(_address); //  Display Data
  
  SPI.transfer(_address);
  delayMicroseconds(8);
  //  read 1 register
  SPI.transfer(0x00);
  //  No Operation (NOP) to retrieve the data
  byte rData = SPI.transfer(command);

  Serial.println("byte read: ");
  readByteFull(rData); //  Display Data
  return rData;
}

byte readRegister(byte address) {
  byte _address = PREG_CMD | address;
  
  Serial.println("address: ");
  readByteFull(_address); //  Display Data
  
  SPI.transfer(_address);
  delayMicroseconds(8);
  //  read 1 register
  SPI.transfer(0x00);
  //  No Operation (NOP) to retrieve the data
  byte rData = SPI.transfer(0x00);

  Serial.println("byte read: ");
  readByteFull(rData); //  Display Data

  delayMicroseconds(2);
  return rData;
}

byte getDeviceID() {
  readRegister(0x00);
  //  This returns device ID, something like 00111110
  //  The last two bits indicate how many channels is availble
  //  00 -> 4 channels, 01 -> 6 channels, 10 -> 8 channels
  byte deviceID = SPI.transfer(0x00);
  return deviceID;
}
