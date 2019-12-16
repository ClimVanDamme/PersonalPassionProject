#include <CapacitiveSensor.h>
#define AMT_CAPSENSORS 32


/*
   CapitiveSense Library Demo Sketch
   Paul Badger 2008
   Uses a high value resistor e.g. 10M between send pin and receive pin
   Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
   Receive pin is the sensor pin - try different amounts of foil/metal on this pin
*/


int capSendPin = 7;
int led = 13;
int lasttouched = -1;
int lastTotal = -1;

long total[AMT_CAPSENSORS];
CapacitiveSensor capSensors[AMT_CAPSENSORS] = {

  CapacitiveSensor(capSendPin, 22),
  CapacitiveSensor(capSendPin, 23),
  CapacitiveSensor(capSendPin, 24),
  CapacitiveSensor(capSendPin, 25),
  CapacitiveSensor(capSendPin, 26),
  CapacitiveSensor(capSendPin, 27),
  CapacitiveSensor(capSendPin, 28),
  CapacitiveSensor(capSendPin, 29),
  CapacitiveSensor(capSendPin, 30),
  CapacitiveSensor(capSendPin, 31),
  CapacitiveSensor(capSendPin, 32),
  CapacitiveSensor(capSendPin, 33),
  CapacitiveSensor(capSendPin, 34),
  CapacitiveSensor(capSendPin, 35),
  CapacitiveSensor(capSendPin, 36),
  CapacitiveSensor(capSendPin, 37),
  CapacitiveSensor(capSendPin, 38),
  CapacitiveSensor(capSendPin, 39),
  CapacitiveSensor(capSendPin, 40),
  CapacitiveSensor(capSendPin, 41),
  CapacitiveSensor(capSendPin, 42),
  CapacitiveSensor(capSendPin, 43),
  CapacitiveSensor(capSendPin, 44),
  CapacitiveSensor(capSendPin, 45),
  CapacitiveSensor(capSendPin, 46),
  CapacitiveSensor(capSendPin, 47),
  CapacitiveSensor(capSendPin, 48),
  CapacitiveSensor(capSendPin, 49),
  CapacitiveSensor(capSendPin, 50),
  CapacitiveSensor(capSendPin, 51),
  CapacitiveSensor(capSendPin, 52),
  CapacitiveSensor(capSendPin, 53)

};

void setup()
{
  //cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  long start = millis();

  //Serial.println(lasttouched);

  for (int i = 0; i < AMT_CAPSENSORS; i++) {
    total[i] = capSensors[i].capacitiveSensor(30);

    //Serial.println(total[i]);

    if (total[i] > lastTotal + 100 && lasttouched != i) {
      Serial.println(i + 22); Serial.println("aangeraakt"); //Serial.println("waarde"); Serial.println(total[i]);
      lasttouched = i;
      lastTotal = total[i];
      digitalWrite(led, HIGH);
    }


    if (total[i] < lastTotal - 100 && lasttouched == i) {
      Serial.println(i + 22); Serial.println("losgelaten"); //Serial.println("waarde"); Serial.println(total[i]);
      lasttouched = -1;
      lastTotal = -1;
      digitalWrite(led, LOW);
    }


  }
  //Serial.println(total[7]);
  delay(10);                             // arbitrary delay to limit data to serial port
}
