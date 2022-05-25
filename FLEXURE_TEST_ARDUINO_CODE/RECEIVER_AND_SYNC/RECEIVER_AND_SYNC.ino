const unsigned long PERIOD = 500;
unsigned long lastTime = 0;
const int PIN = 13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); 
pinMode(PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (millis() - lastTime >= PERIOD) {
  lastTime=millis();
  digitalWrite(PIN , HIGH);
  Serial.println("HIGH");
  }
else {
  digitalWrite(PIN,LOW);
  }
}
