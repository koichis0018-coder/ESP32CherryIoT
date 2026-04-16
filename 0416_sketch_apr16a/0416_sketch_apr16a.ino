const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB
 
#define RE 293.665
#define _RE 311.127
#define H_RE   1174.66 // 高いレ
#define H_REs  1244.51 // 高い(レ#) 緊張感を出すための半音
#define H_FA   1396.91 // 高いミ
#define H_FAs  1479.98 // 高い(ファ#) 
#define H_SO   1567.98 // (ソ) 

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

  ledcWriteTone(spkrPin, _RE);
  delay(10);
  ledcWriteTone(spkrPin, RE);
  delay(10);
  ledcWriteTone(spkrPin, _RE);
  delay(150);
  ledcWriteTone(spkrPin, H_FAs);
  delay(10);
  ledcWriteTone(spkrPin, H_FAs);
  delay(10);
  ledcWriteTone(spkrPin, H_FAs);
  delay(150);
  ledcWriteTone(spkrPin, H_FAs);
  delay(500);
    
  } else {
    digitalWrite(spkrPin, LOW); //OFF
    Serial.println("OFF");
    delay(500);
  }
  
}

