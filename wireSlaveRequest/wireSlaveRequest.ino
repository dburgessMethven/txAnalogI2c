// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <I2C_Anything.h>

char c[4] = {49, 48, 50, 52};
char d[6] = "hello";
int e = 1024;
int sensor = 1024;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {

}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
   for (int i = 0; i <= 6; i++) {
  I2C_writeAnything (c); // respond with message of 6 bytes

  }
}
