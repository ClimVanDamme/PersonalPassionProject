#include "Arduino.h"
//#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
//#include <CapacitiveSensor.h>
#include "SoftwareSerial.h"


DFRobotDFPlayerMini myDFPlayer1;
DFRobotDFPlayerMini myDFPlayer2;
DFRobotDFPlayerMini myDFPlayer3;
DFRobotDFPlayerMini myDFPlayer4;

 SoftwareSerial mySoftwareSerial(10, 11); // RX, TX

void printDetail(uint8_t type, int value);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  mySoftwareSerial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);

  //Serial.begin(115200);


  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer1.begin(mySoftwareSerial)) { 
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the 1st connection!"));
    Serial.println(F("2.Please insert the 1st SD card!"));
    while(true);
   }

 Serial.println(F("DFPlayer Mini 1 online."));


  if (!myDFPlayer2.begin(Serial1)) { 
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the 2nd connection!"));
    Serial.println(F("2.Please insert the 2nd SD card!"));
    while(true);
   }
   
  Serial.println(F("DFPlayer Mini 2 online."));
  

  if (!myDFPlayer3.begin(Serial2)) { 
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the 3th connection!"));
    Serial.println(F("2.Please insert the 3th SD card!"));
    while(true);
   }
   
   Serial.println(F("DFPlayer Mini 3 online."));


  if (!myDFPlayer4.begin(Serial3)) { 
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the 4th connection!"));
    Serial.println(F("2.Please insert the 4th SD card!"));
    while(true);
   }

  Serial.println(F("DFPlayer Mini 4 online."));

  myDFPlayer1.volume(28); 
  myDFPlayer2.volume(28);
  myDFPlayer3.volume(28);
  myDFPlayer4.volume(28);

}

void loop() {
  
  // put your main code here, to run repeatedly:

  static unsigned long timer = millis();

  if (millis() - timer > 3000) {
    timer = millis();
    myDFPlayer1.play(1);
    delay(100);
    myDFPlayer2.play(3);
    delay(100);
    myDFPlayer3.play(5);
    delay(100);
    myDFPlayer4.play(7); 
  }

  

  if (myDFPlayer1.available()) {
    printDetail(myDFPlayer1.readType(), myDFPlayer1.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }

  if (myDFPlayer2.available()) {
    printDetail(myDFPlayer2.readType(), myDFPlayer2.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }

  if (myDFPlayer3.available()) {
    printDetail(myDFPlayer3.readType(), myDFPlayer3.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }

  if (myDFPlayer4.available()) {
    printDetail(myDFPlayer4.readType(), myDFPlayer4.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }
}

void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}
