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
  SPI.setClockDivider(SPI_CLOCK_DIV32);
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
  digitalWrite(RESET,LOW);
  delay(100);
  digitalWrite(RESET, HIGH);
  delay(1000);
  
  digitalWrite(START, HIGH);

  //  at this point, DRDY pin should oscillate around 250Hz

//  SPI.transfer(0b11110100); //CLK_EN
//  delay(100);
//  SPI.transfer(0x11); // SDATAC
//  SPI.transfer(0b11100000); // Internal Ref
//  delay(100);
//  SPI.transfer(0b11010101); // Internal test signal
//  delay(180);
//  SPI.transfer(0b00010000); // RDATAC
}

void loop() {
  
}
