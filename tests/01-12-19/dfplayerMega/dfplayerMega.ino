/***************************************************
DFPlayer - A Mini MP3 Player For Arduino
 <https://www.dfrobot.com/index.php?route=product/product&product_id=1121>

 ***************************************************
 This example shows the basic function of library for DFPlayer.

 Created 2016-12-07
 By [Angelo qiao](Angelo.qiao@dfrobot.com)

 GNU Lesser General Public License.
 See <http://www.gnu.org/licenses/> for details.
 All above must be included in any redistribution
 ****************************************************/

/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
 <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "Arduino.h"
//#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <CapacitiveSensor.h>


//SoftwareSerial mySoftwareSerial(6, 7); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

CapacitiveSensor cap_G6 = CapacitiveSensor(2,3); // 1M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
CapacitiveSensor cap_C6 = CapacitiveSensor(4,5);
CapacitiveSensor cap_E6 = CapacitiveSensor(8,9);
CapacitiveSensor cap_A6 = CapacitiveSensor(10,11);

void setup()
{
  //mySoftwareSerial.begin(9600);
  Serial3.begin(9600);
  
  Serial.begin(115200);

  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  if (!myDFPlayer.begin(Serial3)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.volume(30);  //Set volume value. From 0 to 30
  //myDFPlayer.play(1);  //Play the first mp3
}

void loop()
{
  //static unsigned long timer = millis();

  //if (millis() - timer > 3000) {
   // timer = millis();
   // myDFPlayer.next();  //Play next mp3 every 3 second.
  //}

  long cap_G6_val = cap_G6.capacitiveSensor(50);
  long cap_C6_val = cap_C6.capacitiveSensor(50);
  long cap_E6_val = cap_E6.capacitiveSensor(50);
  long cap_A6_val = cap_A6.capacitiveSensor(50);

 Serial.println( cap_C6_val);

  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }


  if(cap_G6_val >= 500){
        Serial.println("G6 ingedrukt");
        myDFPlayer.play(1);
        delay(100);
     
     }

  if(cap_C6_val >= 500){
        Serial.println("C6 ingedrukt");
        myDFPlayer.play(2);
        delay(100);
     
     }

     
  if(cap_E6_val >= 500){
        Serial.println("E6 ingedrukt");
        myDFPlayer.play(3);
        delay(100);
     
     }

  
  if(cap_A6_val >= 500){
        Serial.println("A6 ingedrukt");
        myDFPlayer.play(4);
        delay(100);
     
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
