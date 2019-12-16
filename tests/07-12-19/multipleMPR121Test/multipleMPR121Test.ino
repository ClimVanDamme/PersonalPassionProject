#include <Wire.h>
#include <Adafruit_MPR121.h>


Adafruit_MPR121 cap1 = Adafruit_MPR121();
Adafruit_MPR121 cap2 = Adafruit_MPR121();
Adafruit_MPR121 cap3 = Adafruit_MPR121();

uint16_t lasttouched1 = 0;
uint16_t currtouched1 = 0;

uint16_t lasttouched2 = 0;
uint16_t currtouched2 = 0;

uint16_t lasttouched3 = 0;
uint16_t currtouched3 = 0;




void setup() { 
Serial.begin(115200);
if (!cap1.begin(0x5A)) {
Serial.println("MPR121 A not found, check wiring?");
while (1);
}
Serial.println("MPR121 A found!");

if (!cap2.begin(0x5B)) {
Serial.println("MPR121 B not found, check wiring?");
while (1);
}
Serial.println("MPR121 B found!");

if (!cap3.begin(0x5C)) {
Serial.println("MPR121 C not found, check wiring?");
while (1);
}
Serial.println("MPR121 C found!");


}

void loop() {
currtouched1 = cap1.touched();

//For A----------------------------------------------------------
for (uint8_t i=0; i<12; i++) {
if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
Serial.print(i); Serial.println(" touched of A");
}

if (!(currtouched1 & _BV(i)) && (lasttouched1 & _BV(i)) ) {
Serial.print(i); Serial.println(" released of A");
}

currtouched2 = cap2.touched();

//For B----------------------------------------------------------
if ((currtouched2 & _BV(i)) && !(lasttouched2 & _BV(i)) ) {
Serial.print(i); Serial.println(" touched of B");
}

if (!(currtouched2 & _BV(i)) && (lasttouched2 & _BV(i)) ) {
Serial.print(i); Serial.println(" released of B");
}



currtouched3 = cap3.touched();
//For C----------------------------------------------------------
if ((currtouched3 & _BV(i)) && !(lasttouched3 & _BV(i)) ) {
Serial.print(i); Serial.println(" touched of C");
}

if (!(currtouched3 & _BV(i)) && (lasttouched3 & _BV(i)) ) {
Serial.print(i); Serial.println(" released of C");
}
}

lasttouched1 = currtouched1;
lasttouched2 = currtouched2;
lasttouched3 = currtouched3;
return;
}
