#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <CapacitiveSensor.h>


SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayerOne;
DFRobotDFPlayerMini myDFPlayerTwo;
DFRobotDFPlayerMini myDFPlayerThree;
DFRobotDFPlayerMini myDFPlayerFour;


CapacitiveSensor noteOne = CapacitiveSensor(22,23);
CapacitiveSensor noteTwo = CapacitiveSensor(24,25);
CapacitiveSensor noteThree = CapacitiveSensor(26,27);
CapacitiveSensor noteFour = CapacitiveSensor(28,29);





void setup()
{
  
  mySoftwareSerial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);


  //Serial.begin(115200);



  myDFPlayerOne.begin(mySoftwareSerial);
  myDFPlayerTwo.begin(Serial1);
  myDFPlayerThree.begin(Serial2);
  myDFPlayerFour.begin(Serial3);


  myDFPlayerOne.volume(20);  //Set volume value. From 0 to 30
  myDFPlayerTwo.volume(20);
  myDFPlayerThree.volume(20);
  myDFPlayerFour.volume(20);


  myDFPlayerOne.play(1);//Play the first mp3
  myDFPlayerTwo.play(1);
  myDFPlayerThree.play(1);
  myDFPlayerFour.play(1);


}

void loop()
{
  long noteOneVal = noteOne.capacitiveSensor(50);
  long noteTwoVal = noteTwo.capacitiveSensor(50);
  long noteThreeVal = noteThree.capacitiveSensor(50);
  long noteFourVal = noteFour.capacitiveSensor(50);


  if(noteOneVal >= 500){
        Serial.println("noot 1 ingedrukt");
        myDFPlayerOne.play(1);
        delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
     }

  if(noteTwoVal >= 500){
        Serial.println("noot 2 ingedrukt");
        myDFPlayerTwo.play(1);
        delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
     }

   if(noteThreeVal >= 500){
        Serial.println("noot 3 ingedrukt");
        myDFPlayerThree.play(1);
        delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
     }

   if(noteFourVal >= 500){
        Serial.println("noot 4 ingedrukt");
        myDFPlayerFour.play(1);
        delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
     }
}
