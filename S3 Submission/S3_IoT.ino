const int freq = 1000;
const int channel = 0;
const int res = 8;

void setup() {
  Serial.begin(9600);
  pinMode(27, OUTPUT);
  ledcSetup(channel, freq, res);
  ledcAttachPin(27, channel);

}

void loop() {
  int touch1 = 0; //
  touch1 = touchRead(T9);
  Serial.print("The touch value of D32: ");
  Serial.println(touch1);

  int touch2 = 0;
  touch2 = touchRead(T8);
  Serial.print("The touch value of D33:");
  Serial.println(touch2);

  int touch3 = 0;
  touch3 = touchRead(T4);
  Serial.print("The touch value of D13:");
  Serial.println(touch3);

  int touch4 = 0;
  touch4 = touchRead(T5);
  Serial.print("The touch value of D12:");
  Serial.println(touch4);

  if(touch1 < 40) {
    ledcWrite(channel, 255);
    delay(100);
  }
  else if(touch2 < 40) {
    ledcWrite(channel, 280);
    delay(100);
  }
  else if(touch3 < 40) {
    ledcWrite(channel, 300);
    delay(100);
  }

  else if(touch4 < 40) {
    ledcWrite(channel, 220);
    delay(100);
  }

  else{
    ledcWrite(channel, 0);
    delay(100);
  }
}
