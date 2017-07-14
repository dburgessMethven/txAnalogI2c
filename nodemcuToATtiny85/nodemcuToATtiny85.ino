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
volatile byte b = 0;
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  A1Recieved = 0;
  B1Recieved = 0;
  myCounter = 0;
  digitalWrite(LED_BUILTIN, HIGH);
  Wire.requestFrom(8, 1);    // request 6 bytes from slave device #8
  
  while (Wire.available()) { // slave may send less than requested
    b = Wire.read(); // receive a byte as character
      Serial.println(b);

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
    
  }
  //Serial.println(A1Recieved);

  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);
}
