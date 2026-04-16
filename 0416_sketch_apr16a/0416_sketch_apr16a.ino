const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB

#define HIGH_RE 1174.66  // 高いレ
#define HIGH_MI 1318.51  // 高いミ
#define HIGH_FA 1396.91  // 高いファ

#define H_RE   1174.66 // チ
#define H_REs  1244.51 // (レ#) 緊張感を出すための半音
#define H_FA   1396.91 // カ
#define H_FAs  1479.98 // (ファ#) ンーー！のベース
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

  ledcWriteTone(spkrPin, H_REs);
  delay(150);
  ledcWriteTone(spkrPin, H_REs);
  delay(150);
  ledcWriteTone(spkrPin, H_FAs);
  delay(500);
  //ledcWriteTone(spkrPin, HIGH_RE);
  //delay(50);

    
  } else {
    digitalWrite(spkrPin, LOW); //OFF
    Serial.println("OFF");
    delay(500);
  }
  
}

