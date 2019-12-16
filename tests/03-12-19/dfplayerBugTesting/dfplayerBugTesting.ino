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
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
DFRobotDFPlayerMini myDFPlayerTwo;
DFRobotDFPlayerMini myDFPlayerThree;
DFRobotDFPlayerMini myDFPlayerFour;


void setup()
{
  
  mySoftwareSerial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);


  //Serial.begin(115200);



  myDFPlayer.begin(Serial2);
  myDFPlayerTwo.begin(Serial3);
  myDFPlayerThree.begin(mySoftwareSerial);
  myDFPlayerFour.begin(Serial1);


  myDFPlayer.volume(20);  //Set volume value. From 0 to 30
  myDFPlayerTwo.volume(20);
  myDFPlayerThree.volume(20);
  myDFPlayerFour.volume(20);


  myDFPlayer.play(1);//Play the first mp3
  myDFPlayerTwo.play(1);
  myDFPlayerThree.play(1);
  myDFPlayerFour.play(1);


}

void loop()
{

  static unsigned long timer = millis();
    
  if (millis() - timer > 3000) {
    timer = millis();
    myDFPlayer.next();
    myDFPlayerTwo.next();
    myDFPlayerThree.next();
    myDFPlayerFour.next();


  }
}
