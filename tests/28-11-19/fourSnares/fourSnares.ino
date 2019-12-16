#include "pitches.h"
#include <CapacitiveSensor.h>

const int pinLaser = 2; // output signal pin of laser module/laser pointer

const int pinReceiverG = 3; // input signal pin of receiver/detector (the used module does only return a digital state)
const int pinReceiverC = 4; // input signal pin of receiver/detector (the used module does only return a digital state)
const int pinReceiverE = 5; // input signal pin of receiver/detector (the used module does only return a digital state)
//const int pinReceiverA = 6; // input signal pin of receiver/detector (the used module does only return a digital state)




CapacitiveSensor cap_G6 = CapacitiveSensor(8,9); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor cap_C6 = CapacitiveSensor(10,11);
CapacitiveSensor cap_E6 = CapacitiveSensor(6,12);
//CapacitiveSensor cap_A6 = CapacitiveSensor(12,13);



int notes[] = {
NOTE_G6, NOTE_C6, NOTE_E6, NOTE_A6};

int speakerPin = 7;

void setup() {
  pinMode(pinLaser, OUTPUT); // set the laser pin to output mode
  
  pinMode(pinReceiverG, INPUT); // set the laser pin to output mode
  pinMode(pinReceiverC, INPUT); // set the laser pin to output mode
  pinMode(pinReceiverE, INPUT); // set the laser pin to output mode
  //pinMode(pinReceiverA, INPUT); // set the laser pin to output mode

  digitalWrite(pinLaser, HIGH); // emit red laser
  Serial.begin(9600); // Setup serial connection for print out to console
}

void loop() {
  int valueG = digitalRead(pinReceiverG); // receiver/detector send either LOW or HIGH (no analog values!)
  int valueC = digitalRead(pinReceiverC);
  int valueE = digitalRead(pinReceiverE);
  //int valueA = digitalRead(pinReceiverA);
  //delay(100); 
  
  long cap_G6_val = cap_G6.capacitiveSensor(50);
  long cap_C6_val = cap_C6.capacitiveSensor(50);
  long cap_E6_val = cap_E6.capacitiveSensor(50);
  //long cap_A6_val = cap_A6.capacitiveSensor(50);




  if (valueG == 0) {
     // Serial.println("G onderbroken");
     // Serial.println(cap_G6_val);


      // get cap touch input
      if(cap_G6_val >= 500){
        Serial.println("G6 ingedrukt");
        int pitch = 0;
        tone(speakerPin, notes[pitch], 100);
        }
  }

   if (valueC == 0) {
      //Serial.println("C onderbroken");
      //Serial.println(cap_C6_val);


       if(cap_C6_val >= 500){
        Serial.println("C6 ingedrukt");
        int pitch = 1;
        tone(speakerPin, notes[pitch], 100);
        }
  }

   if (valueE == 0) {
      Serial.println("E onderbroken");
      Serial.println(cap_E6_val);


       if(cap_E6_val >= 500){
        Serial.println("E6 ingedrukt");
        int pitch = 2;
        tone(speakerPin, notes[pitch], 100);
        }
  }
}
