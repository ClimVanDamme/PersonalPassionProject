#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <CapacitiveSensor.h>

#define NOTES_PER_SNARE 4

CapacitiveSensor *notesSnareOne[NOTES_PER_SNARE] = {new CapacitiveSensor(22,23), new CapacitiveSensor(24,25), new CapacitiveSensor(26,27), new CapacitiveSensor(28,29)};


SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayerOne;
DFRobotDFPlayerMini myDFPlayerTwo;
DFRobotDFPlayerMini myDFPlayerThree;
DFRobotDFPlayerMini myDFPlayerFour;

const int tunerOne = A0;
int transposeValue = 0;

int samplePreset = 1;



void setup()
{      
  mySoftwareSerial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);


  Serial.begin(115200);



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

  transposeValue = analogRead(tunerOne);
  int transpose = map(transposeValue, 0, 1023, 0, 21);
  Serial.println("transpose");
  Serial.println(transpose);
  long snareOneValues[] = {notesSnareOne[0]->capacitiveSensor(50), notesSnareOne[1]->capacitiveSensor(50), notesSnareOne[2]->capacitiveSensor(50), notesSnareOne[3]->capacitiveSensor(50)};


  for (int i = 0; i < NOTES_PER_SNARE; i++) {
    if(snareOneValues[i] >= 500){
        //Serial.println("noot");
        //Serial.println(i);
        //Serial.println("ingedrukt");
        myDFPlayerOne.playFolder(samplePreset, i+1+transpose);
        delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
     }
  }
}
