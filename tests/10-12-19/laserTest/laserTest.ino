const int pinReceiver1 = 3;
const int pinReceiver2 = 4;

const int pinReceiver3 = 5;

const int pinReceiver4 = 6;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(pinReceiver1, INPUT);
   pinMode(pinReceiver2, INPUT);
    pinMode(pinReceiver3, INPUT);
     pinMode(pinReceiver4, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int valueReceiver1 = digitalRead(pinReceiver1);
  int valueReceiver2 = digitalRead(pinReceiver2);
  int valueReceiver3 = digitalRead(pinReceiver3);
  int valueReceiver4 = digitalRead(pinReceiver4);

 // Serial.println(valueReceiver4);

  
  if (valueReceiver1 == 0) {
    Serial.println("1 onderbroken");
  }

  if (valueReceiver2 == 0) {
    Serial.println("2 onderbroken");
  }
  if (valueReceiver3 == 0) {
    Serial.println("3 onderbroken");
  }

  if (valueReceiver4 == 0) {
    Serial.println("4 onderbroken");
  }

  delay(10);
  
}
