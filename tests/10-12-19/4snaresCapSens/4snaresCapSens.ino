#include <Wire.h>
#include <Adafruit_MPR121.h>
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);


int samplePreset = 2;

Adafruit_MPR121 capA = Adafruit_MPR121();
Adafruit_MPR121 capB = Adafruit_MPR121();
Adafruit_MPR121 capC = Adafruit_MPR121();



uint16_t lasttouchedA = 0;
uint16_t currtouchedA = 0;

uint16_t lasttouchedB = 0;
uint16_t currtouchedB = 0;

uint16_t lasttouchedC = 0;
uint16_t currtouchedC = 0;




void setup() {
  mySoftwareSerial.begin(9600);


  Serial.begin(115200);
  if (!capA.begin(0x5A)) {
    Serial.println("MPR121 A not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 A found!");

  if (!capB.begin(0x5B)) {
    Serial.println("MPR121 B not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 B found!");

  if (!capC.begin(0x5C)) {
    Serial.println("MPR121 C not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 C found!");

  // dfplayers
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));
  
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
  myDFPlayer.play(1);  //Play the first mp3

  capA.setThreshholds(24, 12);
    capB.setThreshholds(24, 12);
      capC.setThreshholds(24, 12);

}

void loop() {
  //Serial.print("In functie initialiseNotes");
  currtouchedA = capA.touched();
  currtouchedB = capB.touched();
  currtouchedC = capC.touched();

  int transposeSnareOne = 0;




  //For A----------------------------------------------------------
  for (uint8_t i = 0; i < 12; i++) {
    if ((currtouchedA & _BV(i)) && !(lasttouchedA & _BV(i)) ) {
      switch (i) {
        case 0:
          Serial.print("0");
          //myDFPlayer.playFolder(samplePreset, 1 + transposeSnareOne);
          delay(50);
          break;
        case 1:
          Serial.print("1");
          //myDFPlayer.playFolder(samplePreset, 2 + transposeSnareOne);
          delay(50);
          break;
        case 2:
          Serial.print("2");
          //myDFPlayer.playFolder(samplePreset, 3 + transposeSnareOne);
          delay(50);
          break;
        case 3:
          Serial.print("3");
         //myDFPlayer.playFolder(samplePreset, 4 + transposeSnareOne);
          delay(50);
          break;
        case 4:
          Serial.print("4");
          //myDFPlayer.playFolder(samplePreset, 5 + transposeSnareOne);
          delay(50);
          break;
        case 5:
          Serial.print("5");
          //myDFPlayer.playFolder(samplePreset, 6 + transposeSnareOne);
          delay(50);
          break;
        case 6:
          Serial.print("6");
          //myDFPlayer.playFolder(samplePreset, 7 + transposeSnareOne);
          delay(50);
          break;
        case 7:
          Serial.print("7");
          //myDFPlayer.playFolder(samplePreset, 8 + transposeSnareOne);
          delay(50);
          break;
        case 8:
          Serial.print("8");
          //myDFPlayer.playFolder(samplePreset, 9 + transposeSnareOne);
          delay(50);
          break;
        case 9:
          Serial.print("9");
          break;
        case 10:
          Serial.print("10");
          break;
        case 11:
          Serial.print("11");
          break;
      }
    }

    if (!(currtouchedA & _BV(i)) && (lasttouchedA & _BV(i)) ) {
      Serial.print(i); Serial.println(" released of A");
    }


    //For B----------------------------------------------------------
    if ((currtouchedB & _BV(i)) && !(lasttouchedB & _BV(i)) ) {
      switch (i) {
        case 0:
          Serial.print("0");
          break;
        case 1:
          Serial.print("1");
          break;
        case 2:
          Serial.print("2");
          break;
        case 3:
          Serial.print("3");
          break;
        case 4:
          Serial.print("4");
          break;
        case 5:
          Serial.print("5");
          break;
        case 6:
          Serial.print("6");
          break;
        case 7:
          Serial.print("7");
          break;
        case 8:
          Serial.print("8");
          break;
        case 9:
          Serial.print("9");
          break;
        case 10:
          Serial.print("10");
          break;
        case 11:
          Serial.print("11");
          break;
      }
    }

    if (!(currtouchedB & _BV(i)) && (lasttouchedB & _BV(i)) ) {
      Serial.print(i); Serial.println(" released of B");
    }


    //For C----------------------------------------------------------
    if ((currtouchedC & _BV(i)) && !(lasttouchedC & _BV(i)) ) {
      switch (i) {
        case 0:
          Serial.print("0");
          break;
        case 1:
          Serial.print("1");
          break;
        case 2:
          Serial.print("2");
          break;
        case 3:
          Serial.print("3");
          break;
        case 4:
          Serial.print("4");
          break;
        case 5:
          Serial.print("5");
          break;
        case 6:
          Serial.print("6");
          break;
        case 7:
          Serial.print("7");
          break;
        case 8:
          Serial.print("8");
          break;
        case 9:
          Serial.print("9");
          break;
        case 10:
          Serial.print("10");
          break;
        case 11:
          Serial.print("11");
          break;
      }
    }

    if (!(currtouchedC & _BV(i)) && (lasttouchedC & _BV(i)) ) {
      Serial.print(i); Serial.println(" released of C");
    }
  }

  lasttouchedA = currtouchedA;
  lasttouchedB = currtouchedB;
  lasttouchedC = currtouchedC;
  return;
}
