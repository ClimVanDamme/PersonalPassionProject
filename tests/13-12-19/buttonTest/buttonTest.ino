const int buttonReceiver = 9;
int samplePreset = 1;


void setup() {
  

  // put your setup code here, to run once:
  Serial.begin(115200);
   pinMode(buttonReceiver, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
  cyclePresets();
  Serial.println(samplePreset);

 
}


void cyclePresets () {

  int buttonValue = digitalRead(buttonReceiver);
  
     if(buttonValue == 0) {
      samplePreset++;
      delay(500);
    }

  if(samplePreset == 5) {
      samplePreset = 1;
    }
  }
