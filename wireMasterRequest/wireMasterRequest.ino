// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

int myCounter = 0;
int A1Recieved = 0;
int B1Recieved = 0;
volatile char c;

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  A1Recieved = 0;
  B1Recieved = 0;
  myCounter = 0;
  Wire.requestFrom(8, 8);    // request 6 bytes from slave device #8
  while (Wire.available()) { // slave may send less than requested
    c = Wire.read(); // receive a byte as character
    if (Wire.endTransmission () == 0)
    {
      digitalWrite(LED_BUILTIN, LOW);

    }
    else
    {
      // failure ... maybe slave wasn't ready or not connected
    }
    if (myCounter == 0) {
      A1Recieved = (c - 48);
    }
    if (myCounter == 4) {
      B1Recieved = (c - 48);
    }
    if (1 <= myCounter && myCounter <= 3) {
      A1Recieved = A1Recieved * 10 + (c - 48);
    }
    if (5 <= myCounter && myCounter <= 8) {
      B1Recieved = B1Recieved * 10 + (c - 48);
    }

    myCounter++;
    // Serial.print(c);
    digitalWrite(LED_BUILTIN, HIGH);
  }
  Serial.println(A1Recieved);
  Serial.println(B1Recieved);
  delay(1000);
}
