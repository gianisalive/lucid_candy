#include <SPI.h>

const int RESET = 3;
const int START = 4;
const int CS = 5;
const int DRDY = 6;
const int CLKSEL = 7;
const int MOSI_GATE = 8;

void setup() {
  Serial.begin(9600);
  //  spi set up
  SPI.begin();
  SPI.setDataMode(SPI_MODE1);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  SPI.setBitOrder(MSBFIRST);

  //  pin set up
  pinMode(RESET, OUTPUT); // Currently not used, reset command is sent to DIN pin instead
  digitalWrite(RESET, LOW);
  pinMode(START, OUTPUT);
  digitalWrite(START, LOW);
  pinMode(CS, OUTPUT);
  digitalWrite(CS, LOW);
  pinMode(DRDY, INPUT);
  pinMode(CLKSEL, OUTPUT); // Used to select internal or external clock
  digitalWrite(CLKSEL, LOW);
  pinMode(MOSI_GATE, OUTPUT);
  digitalWrite(MOSI_GATE, HIGH);
  delay(2000);

  //  TODO: All the timing can be improved.

  //  set CLKSEL pin to 1 to use internal oscillator
  //  Tclk: 2.048 MHz
  digitalWrite(CLKSEL, HIGH);
  delay(100);

  digitalWrite(RESET, HIGH);
  //  wait for VCAP1 to settle to 1.1V
  delay(2000);

  //  RESET & wait 18 clock cycles
  SPI.transfer(0x06);
  delayMicroseconds(32);

  //  SDATA
  SPI.transfer(0x11);
  delayMicroseconds(10);

  //  CONFIG1
  //  CLK_EN = 1 -> enable internal clock output
  //  DR = 110 -> fMOD/4096
  SPI.transfer(0b01000001);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b10110110);
  delayMicroseconds(20);

  //  PDB_REFBUF = 1 -> use internal reference
  SPI.transfer(0b01000011);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b11100000);
  delay(1000);

  //CONFIG2 C0h
  SPI.transfer(0b01000010);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b11000000);
  delayMicroseconds(20);

  //  short channel 1 input
  SPI.transfer(0b01000101);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  short channel 2 input
  SPI.transfer(0b01000110);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  short channel 3 input
  SPI.transfer(0b01000111);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  short channel 4 input
  SPI.transfer(0b01001000);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  short channel 5 input
  SPI.transfer(0b01001001);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  short channel 6 input
  SPI.transfer(0b01001010);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  short channel 7 input
  SPI.transfer(0b01001011);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  short channel 8 input
  SPI.transfer(0b01001100);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b00000001);
  delayMicroseconds(20);

  //  generate test signal
  //  CONFIG2 INT_CAL = 1
  SPI.transfer(0b01000010);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b11110011);
  delayMicroseconds(20);

  //  START
  digitalWrite(START, HIGH);
}

void loop() {
  Serial.println("------- DATA BEGIN -------");
  byteRead(getDeviceID());
  Serial.println("------- DATA END -------");
  delay(3000);
}

//  Read every bit including leading zero
void byteRead(byte byteOfData) {
  for (byte i = 0; i < 8; i++) {
    Serial.print(bitRead(byteOfData, 7 - i));
  }
  Serial.print("\n");
}


byte getDeviceID() {
  //  Select address
  SPI.transfer(0b00100000);
  delayMicroseconds(2);
  //  Number for addresses to read from, starting from the address selected above
  SPI.transfer(0b00000000);
  //  This returns device ID, something like 00111110
  //  The last two bits indicate how many channels is availble
  //  00 -> 4 channels, 01 -> 6 channels, 10 -> 8 channels
  byte deviceID = SPI.transfer(0x00);
  return deviceID;
}
