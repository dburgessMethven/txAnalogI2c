#include <math.h>
#define thermistorAPIN A3
#define THERMISTORNOMINALboiler 10000 //increase this value to bump up the measured temperature readout
#define TEMPERATURENOMINAL 25
#define NUMSAMPLES 5
#define BCOEFFICIENT 3950
#define SERIESRESISTOR 10000
#include "TinyWireS.h"                  // wrapper class for I2C slave routines
#include <avr/wdt.h>

int blinkPin=0;
char d[6] = "h";
int e = 1024;
int f = 1024;
byte temp = 55;
int analogReadAverager(byte(num), int(analogPin)) {
  int samples[num];
  uint8_t i = 0;
  int average = 0;
  for (i = 0; i < num; i++) {
    samples[i] = analogRead(analogPin);
    delay(10);
  }
  for (i = 0; i < num; i++) {
    average += samples[i];
  }
  average /= num;
  return average;
}

void reboot(
    ) {

cli();
WDTCR = 0xD8 | WDTO_1S;
sei();

wdt_reset();
while (true) {}

} 
// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  e = analogReadAverager(NUMSAMPLES, thermistorAPIN);

  int myA1 = (e / 1000);
  int myA2 = ((e - (1000 * myA1)) / 100);
  int myA3 = ((e - (1000 * myA1) - (100 * myA2)) / 10);
  int myA4 = (e - (1000 * myA1) - (100 * myA2) - (10 * myA3));
  int myB1 = (f / 1000);
  int myB2 = ((f - (1000 * myB1)) / 100);
  int myB3 = ((f - (1000 * myB1) - (100 * myB2)) / 10);
  int myB4 = (f - (1000 * myB1) - (100 * myB2) - (10 * myB3));

  char c[8] = {myA1 + 48, myA2 + 48, myA3 + 48, myA4 + 48, myB1 + 48, myB2 + 48, myB3 + 48, myB4 + 48};
  

  for (int i = 0; i <= 8; i++) {
    TinyWireS.send (temp); // respond with message of 6 bytes
    //   Serial.print (c[i]);
    /*
      Wire.write(myFirst);
      Wire.write(mySecond);
      Wire.write(myThird);
      Wire.write(myForth);
    */
  }
}

void setup() {
  wdt_disable();
  TinyWireS.begin(8);                // join i2c bus with address #8
 TinyWireS.onRequest(requestEvent); // register event


}


void loop() {
if (1==1) reboot2();
}

void reboot2() {
wdt_enable(WDTO_2S);
while(1){};
}


