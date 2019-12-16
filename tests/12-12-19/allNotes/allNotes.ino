#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <CapacitiveSensor.h>

#define NOTES_PER_SNARE 8
#define AMT_DFPLAYERS 4

int capSendPin = 2;
boolean standardTuning = false;

CapacitiveSensor *notesSnareOne[NOTES_PER_SNARE] = {

  new CapacitiveSensor(capSendPin, 22),
  new CapacitiveSensor(capSendPin, 23),
  new CapacitiveSensor(capSendPin, 24),
  new CapacitiveSensor(capSendPin, 25),
  new CapacitiveSensor(capSendPin, 26),
  new CapacitiveSensor(capSendPin, 27),
  new CapacitiveSensor(capSendPin, 28),
  new CapacitiveSensor(capSendPin, 29)

};


CapacitiveSensor *notesSnareTwo[NOTES_PER_SNARE] = {

  new CapacitiveSensor(capSendPin, 30),
  new CapacitiveSensor(capSendPin, 31),
  new CapacitiveSensor(capSendPin, 32),
  new CapacitiveSensor(capSendPin, 33),
  new CapacitiveSensor(capSendPin, 34),
  new CapacitiveSensor(capSendPin, 35),
  new CapacitiveSensor(capSendPin, 36),
  new CapacitiveSensor(capSendPin, 37)

};
CapacitiveSensor *notesSnareThree[NOTES_PER_SNARE] = {

  new CapacitiveSensor(capSendPin, 38),
  new CapacitiveSensor(capSendPin, 39),
  new CapacitiveSensor(capSendPin, 40),
  new CapacitiveSensor(capSendPin, 41),
  new CapacitiveSensor(capSendPin, 42),
  new CapacitiveSensor(capSendPin, 43),
  new CapacitiveSensor(capSendPin, 44),
  new CapacitiveSensor(capSendPin, 45)

};
CapacitiveSensor *notesSnareFour[NOTES_PER_SNARE] = {

  new CapacitiveSensor(capSendPin, 46),
  new CapacitiveSensor(capSendPin, 47),
  new CapacitiveSensor(capSendPin, 48),
  new CapacitiveSensor(capSendPin, 49),
  new CapacitiveSensor(capSendPin, 50),
  new CapacitiveSensor(capSendPin, 51),
  new CapacitiveSensor(capSendPin, 52),
  new CapacitiveSensor(capSendPin, 53)

};




DFRobotDFPlayerMini dfplayers[AMT_DFPLAYERS] = {

  DFRobotDFPlayerMini(),
  DFRobotDFPlayerMini(),
  DFRobotDFPlayerMini(),
  DFRobotDFPlayerMini(),

};


SoftwareSerial mySoftwareSerial(10, 12);

const int tunerOne = A0;
int transposeValueOne = 0;

int samplePreset = 1;



void setup()
{
  mySoftwareSerial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);


  Serial.begin(115200);



  dfplayers[0].begin(mySoftwareSerial);
  dfplayers[1].begin(Serial1);
  dfplayers[2].begin(Serial2);
  dfplayers[3].begin(Serial3);


  for (int i = 0; i < AMT_DFPLAYERS; i++) {
    dfplayers[i].volume(28);
  }

  dfplayers[0].play(1);
  dfplayers[1].play(1);
  dfplayers[2].play(1);
  dfplayers[3].play(1);

}

void loop()
{

  transposeValueOne = analogRead(tunerOne);
  //int transpose = map(transposeValueOne, 0, 1023, 0, 17);
  int transposeOne = 0;
  int transpose = 0;
  //Serial.println("transpose");
  //Serial.println(transpose);


  long snareOneValues[] = {

    notesSnareOne[0]->capacitiveSensor(50),
    notesSnareOne[1]->capacitiveSensor(50),
    notesSnareOne[2]->capacitiveSensor(50),
    notesSnareOne[3]->capacitiveSensor(50),
    notesSnareOne[4]->capacitiveSensor(50),
    notesSnareOne[5]->capacitiveSensor(50),
    notesSnareOne[6]->capacitiveSensor(50),
    notesSnareOne[7]->capacitiveSensor(50)

  };

  long snareTwoValues[] = {

    notesSnareTwo[0]->capacitiveSensor(50),
    notesSnareTwo[1]->capacitiveSensor(50),
    notesSnareTwo[2]->capacitiveSensor(50),
    notesSnareTwo[3]->capacitiveSensor(50),
    notesSnareTwo[4]->capacitiveSensor(50),
    notesSnareTwo[5]->capacitiveSensor(50),
    notesSnareTwo[6]->capacitiveSensor(50),
    notesSnareTwo[7]->capacitiveSensor(50)

  };

  long snareThreeValues[] = {

    notesSnareThree[0]->capacitiveSensor(50),
    notesSnareThree[1]->capacitiveSensor(50),
    notesSnareThree[2]->capacitiveSensor(50),
    notesSnareThree[3]->capacitiveSensor(50),
    notesSnareThree[4]->capacitiveSensor(50),
    notesSnareThree[5]->capacitiveSensor(50),
    notesSnareThree[6]->capacitiveSensor(50),
    notesSnareThree[7]->capacitiveSensor(50)

  };

  long snareFourValues[] = {

    notesSnareFour[0]->capacitiveSensor(50),
    notesSnareFour[1]->capacitiveSensor(50),
    notesSnareFour[2]->capacitiveSensor(50),
    notesSnareFour[3]->capacitiveSensor(50),
    notesSnareFour[4]->capacitiveSensor(50),
    notesSnareFour[5]->capacitiveSensor(50),
    notesSnareFour[6]->capacitiveSensor(50),
    notesSnareFour[7]->capacitiveSensor(50)

  };


  for (int i = 0; i < NOTES_PER_SNARE; i++) {

    //Serial.println(snareOneValues[i]);
    
    if (snareOneValues[i] >= 300) {
      Serial.println("noot");
      Serial.println(i);
      Serial.println("ingedrukt snaar 1");
      dfplayers[0].playFolder(samplePreset, i + 1 + transposeOne);
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
    }

    if (snareTwoValues[i] >= 300) {
      Serial.println("noot");
      Serial.println(i);
      Serial.println("ingedrukt snaar 2");
      dfplayers[1].playFolder(samplePreset, i + 1 + transpose);
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
    }

    if (snareThreeValues[i] >= 300) {
      Serial.println("noot");
      Serial.println(i);
      Serial.println("ingedrukt snaar 3");
      dfplayers[2].playFolder(samplePreset, i + 1 + transpose);
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
    }

    if (snareFourValues[i] >= 300) {
      Serial.println("noot");
      Serial.println(i);
      Serial.println("ingedrukt snaar 4");
      dfplayers[3].playFolder(samplePreset, i + 1 + transpose);
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren
    }
  }

  if (transposeOne == 0 || transposeOne == 8) {
      standardTuning = true;
    }

    //Serial.println(standardTuning);
}
