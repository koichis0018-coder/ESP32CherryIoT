const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int spkrPin = 4; //3:ConnectorA 4:ConnectorB

#define HIGH_RE 1174.66  // 高いレ
#define HIGH_MI 1318.51  // 高いミ
#define HIGH_FA 1396.91  // 高いファ

#define BEAT 230
#define DO 261.6
#define _DO 277.18
#define RE 293.665
#define _RE 311.127
#define MI 329.63
#define FA 349.228
#define _FA 369.994
#define SO 391.995
#define _SO 415.305
#define RA 440
#define _RA 466.164
#define TI 493.883
#define octDO 523.251

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
  delay(1000);
    
  } else {
    digitalWrite(spkrPin, LOW); //OFF
    Serial.println("OFF");
    delay(500);
  }
  
}

