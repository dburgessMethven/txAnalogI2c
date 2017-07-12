// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <I2C_Anything.h>




char d[6] = "h";
int e = 1151;
int f = 1584;

int myA1=(e/1000);
int myA2=((e-(1000*myA1))/100);
int myA3=((e-(1000*myA1)-(100*myA2))/10);
int myA4=(e-(1000*myA1)-(100*myA2)-(10*myA3));
int myB1=(f/1000);
int myB2=((f-(1000*myB1))/100);
int myB3=((f-(1000*myB1)-(100*myB2))/10);
int myB4=(f-(1000*myB1)-(100*myB2)-(10*myB3));

char c[8] = {myA1+48, myA2+48, myA3+48, myA4+48, myB1+48, myB2+48, myB3+48, myB4+48};

int sensor = 1024;
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);
  
}


void loop() {

}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {

  for (int i = 0; i <= 8; i++) {
    Wire.write (c); // respond with message of 6 bytes
 //   Serial.print (c[i]);
 /*
  Wire.write(myFirst);
  Wire.write(mySecond);
  Wire.write(myThird);
  Wire.write(myForth);
  */  }
}
