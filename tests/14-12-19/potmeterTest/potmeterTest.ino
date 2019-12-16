const int tunerOne = A0;
const int tunerTwo = A1;
const int tunerThree = A2;
const int tunerFour = A3;


void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  int transposeValueOne = analogRead(tunerOne);
  int transposeValueTwo = analogRead(tunerTwo);
  int transposeValueThree = analogRead(tunerThree);
  int transposeValueFour = analogRead(tunerFour);

  Serial.println(tunerFour);

}
