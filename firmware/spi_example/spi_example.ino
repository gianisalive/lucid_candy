#include <SPI.h>

//  Command Definitions, data sheet pg. 40
//  System Commands
#define WAKEUP_CMD  0x02
#define STANDBY_CMD 0x04
#define RESET_CMD   0x06
#define START_CMD   0x08
#define STOP_CMD    0x0A

//  Data Read Commands
#define RDATAC_CMD  0x10
#define SDATAC_CMD  0x11
#define RDATA_CMD   0x12

//  Register Read & Write
#define PREG_CMD    0x20
#define WREG_CMD    0x40

//  PIN
const int RESET_PIN = 3;
const int START_PIN = 4;
const int CS_PIN = 5;
const int DRDY_PIN = 6;
const int CLKSEL_PIN = 7;

void setup() {
  Serial.begin(9600);
  Serial.println("=========== Setting SPI ===========");
  //  SPI Set Up
  SPI.begin();
  //  data sheet pg.12 -> SPI setting: CPOL = 0, CPHA = 1
  //  https://en.wikipedia.org/wiki/Serial_Peripheral_Interface
  SPI.setDataMode(SPI_MODE1);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.setBitOrder(MSBFIRST);

  Serial.println("=========== Setting Pins ===========");
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

  Serial.println("=========== Selecting Oscillator ===========");
  //  Use internal oscillator. It oscillates at 2.048 MHz.
  //  Tclk: 2.048 MHz
  digitalWrite(CLKSEL_PIN, HIGH);
  delay(100);

  Serial.println("=========== Resetting ===========");
  digitalWrite(RESET_PIN, HIGH);
  //  wait for VCAP1 to settle to 1.1V
  delay(500);

  //  RESET & wait 18 clock cycles
  SPI.transfer(RESET_CMD);
  delayMicroseconds(36);

  Serial.println("=========== Stop Data Continuous Mode ===========");
  //  Device wakes up automatically at RDATAC (Read Data Continous) mode.
  //  Send SDATAC (Stop Data Continous) command in order to write to registers.
  SPI.transfer(SDATAC_CMD);
  delayMicroseconds(10);

  Serial.println("=========== Setting CONFIG1 ===========");
  //  CONFIG1
  //  CLK_EN = 1 -> enable internal clock output
  //  DR = 110 -> fMOD/4096
  //  writeToRegister(0b10110110, 0x01);
  writeToRegister(0x96, 0x01);
  delay(10);

  Serial.println("=========== Setting CONFIG2 ===========");
  //CONFIG2 C0h
  //  writeToRegister(0b11000000, 0x02);
  writeToRegister(0xC0, 0x02);
  delay(10);

  Serial.println("=========== Setting CONFIG3 ===========");
  //  CONFIG3
  //  PDB_REFBUF = 1 -> use internal reference
  //  writeToRegister(0b11101100, 0x03);
  writeToRegister(0xE0, 0x03);
  delay(2000);

  Serial.println("=========== Setting Channels ===========");
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

  Serial.println("=========== Start ===========");
  //  START
  digitalWrite(START_PIN, HIGH);
}

void loop() {
  delay(500);
  Serial.println("------- DATA BEGIN -------");
  readDataContinuous(8);
  Serial.println("------- DATA END -------");
  delay(500);
}

//  This returns device ID, something like 00111110
//  The last two bits indicate how many channels is availble
//  00 -> 4 channels, 01 -> 6 channels, 10 -> 8 channels
byte getDeviceID() {
  readRegister(0x00);
  byte deviceID = SPI.transfer(0x00);
  return deviceID;
}

//  Read every bit including leading zero
void readBytesFull(byte byteOfData, int bitNum) {
  for (byte i = 0; i < bitNum; i++) {
    Serial.print(bitRead(byteOfData, (bitNum - 1) - i));
  }
  Serial.print("\n");
}

void writeToRegister(byte command, byte address) {
  byte _address = WREG_CMD | address;

  Serial.println("address: ");
  readBytesFull(_address, 8); //  Display Data
  Serial.println("command: ");
  readBytesFull(command, 8);

  SPI.transfer(_address);
  delayMicroseconds(8);
  //  read 1 register
  SPI.transfer(0x00);
  //  No Operation (NOP) to retrieve the data
  SPI.transfer(command);
}

byte readRegister(byte address) {
  byte _address = PREG_CMD | address;

  Serial.println("address: ");
  readBytesFull(_address, 8); //  Display Data

  SPI.transfer(_address);
  delayMicroseconds(8);
  //  read 1 register
  SPI.transfer(0x00);
  //  No Operation (NOP) to retrieve the data
  byte rData = SPI.transfer(0x00);

  Serial.println("byte read: ");
  readBytesFull(rData, 8); //  Display Data

  delayMicroseconds(2);
  return rData;
}

void readDataContinuous(int channelNumber) {
  //  3 bytes per channel + 3 bytes status data at the beginning
  //  data sheet pg. 39
  int bytesToRead = 3 + (3 * channelNumber);
  SPI.transfer(RDATAC_CMD);
  delayMicroseconds(8);
  //  Bit mask: long is 32 bits variable, only select 0 - 23rd bits
  long mask = 0x00FFFFFF;
  
  unsigned long stat;
  unsigned long channelData [channelNumber];

  //  Map channel 1 through n to 1 iteration
  //  e.g channel 1 is bytes in range 2 - 6
  byte currentChannel = 1;
  byte firstChannelByte = (currentChannel + 1) * 3 - 4;
  byte lastChannelByte = (currentChannel + 1) * 3;

  for (byte i = 0; i < bytesToRead; i += 1) {
    byte data = SPI.transfer(0x00);
    Serial.println(data, BIN);
    if (i < 3) {
      stat = stat << 8;
      stat = stat | data;
    }
    if (i == 2) {
      stat = stat & mask;
    }
    if (i > firstChannelByte && i < lastChannelByte) {
      channelData[currentChannel - 1] = channelData[currentChannel - 1] << 8;
      channelData[currentChannel - 1] = channelData[currentChannel - 1] | data;
    }
    if (i == (lastChannelByte - 1)) {
      channelData[currentChannel - 1] = channelData[currentChannel - 1] & mask;
      currentChannel = currentChannel + 1;
      firstChannelByte = (currentChannel + 1) * 3 - 4;
      lastChannelByte = (currentChannel + 1) * 3;
    }
    delayMicroseconds(8);
  }
  Serial.print("STAT");
  Serial.print("  |  ");
  Serial.print(stat, BIN);
  Serial.print("  |  ");
  Serial.print(stat, HEX);
  Serial.print("\n");
  for (byte x = 0; x < channelNumber; x += 1) {
    Serial.print("Channel");
    Serial.print(x+1);
    Serial.print("  |  ");
    Serial.print(channelData[x], BIN);
    Serial.print("  |  ");
    Serial.print(channelData[x], HEX);
    Serial.print("  |  ");
    Serial.print(channelData[x]);
    Serial.print("  |  ");
    Serial.print(convertChannelData(channelData[x]));
    Serial.print("\n");
  }
  delay(10);
  SPI.transfer(SDATAC_CMD);
}

void readData() {
  SPI.transfer(RDATA_CMD);
  delayMicroseconds(8);
  for (int i = 0; i < 27; i++) {
    byte data = SPI.transfer(0x00);
    Serial.println(data);
  }
  delay(10);
}

float convertChannelData(long data) {
  float scaleFactor = 4.5 / 1 / (2 ^ 23 - 1);
  return sqrt(data * scaleFactor);
}
