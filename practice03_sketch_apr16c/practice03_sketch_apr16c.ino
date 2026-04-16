const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB

void playmusic() {
  // put your setup code here, to run once:
  ledcWriteTone(spkrPin,C4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,D4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,C4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  delay(100);
  ledcWriteTone(spkrPin,C4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,D4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,C4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  delay(100);
  ledcWriteTone(spkrPin,C4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,D4);
  delay(100);
  ledcWriteTone(spkrPin,0);
  ledcWriteTone(spkrPin,C4);
  delay(100);
  ledcWriteTone(spkrPin,0);
}

void setup(){
  Serial.begin(115200);
  pinMode(touchPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)

}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(touchPin)==HIGH) {
    Serial.println("Touch!");
    playmusic();
  } else {
    Serial.println("...");
  }
  delay(250);
}
