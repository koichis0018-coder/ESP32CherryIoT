const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB

#define HIGH_RE 1174.66  // 高いレ
#define HIGH_MI 1318.51  // 高いミ
#define HIGH_FA 1396.91  // 高いファ

bool swState;

void setup() {
  Serial.begin(115200);
  pinMode(swPin, INPUT);
  pinMode(spkrPin, OUTPUT);
  ledcAttach(spkrPin, 12000, 8); //Pin setting(Pin num, Max frequency, Resolution)

}

void loop() {

  if (digitalRead(swPin) == HIGH) {
    swState = !swState;

  ledcWriteTone(spkrPin, HIGH_RE);
  delay(150);
  ledcWriteTone(spkrPin, HIGH_RE);
  delay(150);
  ledcWriteTone(spkrPin, HIGH_FA);
  delay(500);
  ledcWriteTone(spkrPin, HIGH_RE);
  delay(50);

    
  } else {
    digitalWrite(spkrPin, LOW); //OFF
    Serial.println("OFF");
    delay(500);
  }
  
}

