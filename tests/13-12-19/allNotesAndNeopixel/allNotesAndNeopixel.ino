#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <CapacitiveSensor.h>
#include <Adafruit_NeoPixel.h>


#define NOTES_PER_SNARE 8
#define AMT_DFPLAYERS 4

int capTreshhold = 200;
int capSensitivity = 50;

int capSendPin = 2;
boolean standardTuning = false;

int currentChord[4] = {-1, -1, -1, -1};

Adafruit_NeoPixel ring = Adafruit_NeoPixel(12, 6, NEO_GRB + NEO_KHZ800);


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
const int tunerTwo = A1;
const int tunerThree = A2;
const int tunerFour = A3;


int transposeValueOne = 0;
int transposeValueTwo = 0;
int transposeValueThree = 0;
int transposeValueFour = 0;

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

  /* Neopixel */
  ring.begin();
  ring.setBrightness(50);
  ring.show();
}

void loop()
{

/*
  if (currentChord[0] == -1 && currentChord[1] == -1 && currentChord[2] == -1 && currentChord[3] == -1) {
   for (;;) {
     rainbowCycle(20);
    }
  }

  */


  //transponeren snaren
  transposeValueOne = analogRead(tunerOne);
  transposeValueTwo = analogRead(tunerTwo);
  transposeValueThree = analogRead(tunerThree);
  transposeValueFour = analogRead(tunerFour);

  //int transpose = map(transposeValueOne, 0, 1023, 0, 17);
  int transposeOne = 0;
  int transposeTwo = 0;
  int transposeThree = 0;
  int transposeFour = 0;


  long snareOneValues[] = {

    notesSnareOne[0]->capacitiveSensor(capSensitivity),
    notesSnareOne[1]->capacitiveSensor(capSensitivity),
    notesSnareOne[2]->capacitiveSensor(capSensitivity),
    notesSnareOne[3]->capacitiveSensor(capSensitivity),
    notesSnareOne[4]->capacitiveSensor(capSensitivity),
    notesSnareOne[5]->capacitiveSensor(capSensitivity),
    notesSnareOne[6]->capacitiveSensor(capSensitivity),
    notesSnareOne[7]->capacitiveSensor(capSensitivity)

  };

  long snareTwoValues[] = {

    notesSnareTwo[0]->capacitiveSensor(capSensitivity),
    notesSnareTwo[1]->capacitiveSensor(capSensitivity),
    notesSnareTwo[2]->capacitiveSensor(capSensitivity),
    notesSnareTwo[3]->capacitiveSensor(capSensitivity),
    notesSnareTwo[4]->capacitiveSensor(capSensitivity),
    notesSnareTwo[5]->capacitiveSensor(capSensitivity),
    notesSnareTwo[6]->capacitiveSensor(capSensitivity),
    notesSnareTwo[7]->capacitiveSensor(capSensitivity)

  };

  long snareThreeValues[] = {

    notesSnareThree[0]->capacitiveSensor(capSensitivity),
    notesSnareThree[1]->capacitiveSensor(capSensitivity),
    notesSnareThree[2]->capacitiveSensor(capSensitivity),
    notesSnareThree[3]->capacitiveSensor(capSensitivity),
    notesSnareThree[4]->capacitiveSensor(capSensitivity),
    notesSnareThree[5]->capacitiveSensor(capSensitivity),
    notesSnareThree[6]->capacitiveSensor(capSensitivity),
    notesSnareThree[7]->capacitiveSensor(capSensitivity)

  };

  long snareFourValues[] = {

    notesSnareFour[0]->capacitiveSensor(capSensitivity),
    notesSnareFour[1]->capacitiveSensor(capSensitivity),
    notesSnareFour[2]->capacitiveSensor(capSensitivity),
    notesSnareFour[3]->capacitiveSensor(capSensitivity),
    notesSnareFour[4]->capacitiveSensor(capSensitivity),
    notesSnareFour[5]->capacitiveSensor(capSensitivity),
    notesSnareFour[6]->capacitiveSensor(capSensitivity),
    notesSnareFour[7]->capacitiveSensor(capSensitivity)

  };




  for (int i = 0; i < NOTES_PER_SNARE; i++) {

    //Serial.println(snareOneValues[i]);

    if (snareOneValues[i] >= capTreshhold) {
      /*Serial.println("noot");
        Serial.println(i);
        Serial.println("ingedrukt snaar 1");*/
      Serial.println(snareOneValues[i]);
      dfplayers[0].playFolder(samplePreset, i + 1 + transposeOne);
      currentChord[0] = i;
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren

    }


    if (snareOneValues[i] < capTreshhold && currentChord[0] == i) {
      Serial.println(snareOneValues[i]);
      currentChord[0] = -1;

    }



    if (snareTwoValues[i] >= capTreshhold) {
      /*Serial.println("noot");
        Serial.println(i);
        Serial.println("ingedrukt snaar 2");*/
      dfplayers[1].playFolder(samplePreset, i + 1 + transposeTwo);
      currentChord[1] = i;
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren

    }

    if (snareTwoValues[i] < capTreshhold &&  currentChord[1] == i) {
      currentChord[1] = -1;

    }

    if (snareThreeValues[i] >= capTreshhold) {
      /*Serial.println("noot");
        Serial.println(i);
        Serial.println("ingedrukt snaar 3");*/
      dfplayers[2].playFolder(samplePreset, i + 1 + transposeThree);
      currentChord[2] = i;
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren

    }

    if (snareThreeValues[i] < capTreshhold &&  currentChord[2] == i) {

      currentChord[2] = -1;

    }

    if (snareFourValues[i] >= capTreshhold) {
      /* Serial.println("noot");
        Serial.println(i);
        Serial.println("ingedrukt snaar 4");*/
      dfplayers[3].playFolder(samplePreset, i + 1 + transposeFour);
      currentChord[3] = i;
      delay(50); //geen dubbele trigger, illusie tegelijk spelen, responsiviteit verbeteren

    }


    if (snareFourValues[i] < capTreshhold &&  currentChord[3] == i) {

      currentChord[3] = -1;

    }
  }


  //standaardtuning

  if (transposeOne == 0 && transposeTwo == 0 && transposeThree == 0 && transposeFour == 0 || transposeOne == 12 && transposeTwo == 12 && transposeThree == 12 && transposeFour == 12) {
    standardTuning = true;
  }

  if (standardTuning) {
    //Serial.println("standardTuning actief");
    //Serial.println("akkoord");

    for (int i = 0; i < 4; i++) {


      Serial.print("snaar "); Serial.print(i + 1); Serial.print(" noot: "); Serial.print(currentChord[i]);
      Serial.println(" ");

      } 

  }
}
    /*akkoorden herkennen*/
    /*
    //F akkoord

    if (currentChord[0] == 1 && currentChord[1] == -1 && currentChord[2] == 0 && currentChord[3] == 1) {

      Serial.println("F akkoord - groen");
      colorWipe(ring.Color(0, 255, 0), 50); // Green


    }


    //Am akkoord

    if (currentChord[0] == 1 && currentChord[1] == -1 && currentChord[2] == -1 && currentChord[3] == -1) {

      Serial.println("Am akkoord - blauw");
      colorWipe(ring.Color(0, 0, 255), 50); // Blue


    }

    //G akkoord

    if (currentChord[0] == -1 && currentChord[1] == 1 && currentChord[2] == 2 && currentChord[3] == 1) {

      Serial.println("G akkoord - geel");
      colorWipe(ring.Color(0, 255, 255), 50); // Yellow

    }

    //C akkoord

    if (currentChord[0] == -1 && currentChord[1] == -1 && currentChord[2] == -1 && currentChord[3] == 2) {

      Serial.println("C akkoord - rood");
      colorWipe(ring.Color(255, 0, 0), 50); // Red

    }





    //delay(500);

  }
}
*/

/* neoPixel animaties */
/*
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < ring.numPixels(); i++) {
      ring.setPixelColor(i, Wheel(((i * 256 / ring.numPixels()) + j) & 255));
    }
    ring.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return ring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return ring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return ring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < ring.numPixels(); i++) {
    ring.setPixelColor(i, c);
    ring.show();
    delay(wait);
  }
}
*/
