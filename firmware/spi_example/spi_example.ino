#include <SPI.h>

#define RESET   3
#define START   4
#define CS      5
#define DRDY    6
#define CLKSEL  7

boolean deviceIDReturned = false;

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
  delay(2000);

  //  TODO: All the timing can be improved.
 
  //  set CLKSEL pin to 1 to use internal oscillator
  //  Tclk: 2.048 MHz
  digitalWrite(CLKSEL, HIGH);
  delay(100);
  
  digitalWrite(RESET, HIGH);
  //  wait for VCAP1 to settle to 1.1V
  delay(2000);
  //  after start pin is pulled high, DRDY oscillates around 250Hz
  digitalWrite(START, HIGH);

  //  CLK_EN = 1 -> enable internal clock output
  //  DR = 110 -> fMOD/4096
  SPI.transfer(0b01000001);
  delayMicroseconds(2);
  SPI.transfer(0b00000000);
  delayMicroseconds(2);
  SPI.transfer(0b10110110);
  delayMicroseconds(2);
}

void loop() {

}

void getDeviceID() {
  //  This returns device ID, something like 11111111
  byte deviceID = SPI.transfer(0x00);
  Serial.println(deviceID, BIN);
}
