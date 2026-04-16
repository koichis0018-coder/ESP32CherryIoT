const int swPin = 3; //3:ConnectorA 4:ConnectorB
const int motorPin = 4; //3:ConnectorA 4:ConnectorB

bool swState;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(11520);
  pinMode(swPin, INPUT);
  pinMode(motorPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(swPin) == HIGH) {
    swState = !swState;
  }

  if (swState == 1) { 
    digitalWrite(motorPin, HIGH); //ON
    Serial.println("ON");
    delay(300);
  } else {
    digitalWrite(motorPin, LOW); //OFF
    Serial.println("OFF");
    delay(300);
  }

}
