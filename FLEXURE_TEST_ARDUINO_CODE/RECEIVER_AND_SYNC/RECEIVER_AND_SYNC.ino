const unsigned long PERIOD = 500;
unsigned long lastTime = 0;
const int PIN = 6;
char c;
String str_caliper;
String str_loadcell;

boolean caliper_done;
boolean loadcell_done;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PIN, OUTPUT);
  Serial1.begin(115200); //TX RX 1 CALIPER_READER
  Serial2.begin(115200); //TX RX 2 LOAD_CELL
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - lastTime >= PERIOD) {
    lastTime = millis();
    digitalWrite(PIN , HIGH);
    delay(1);
    //Serial.println("HIGH");
  }
  else {
    digitalWrite(PIN, LOW);
  }
  if (Serial1.available()) {
    c = Serial1.read();
    if (c == '\n') {
      //finished message
      caliper_done = true;      
    }
    else {
      str_caliper += c;
    }
  }

  if (Serial2.available()) {
    c = Serial2.read();
    if (c == '\n') {
      //finished message
      loadcell_done = true;      
    }
    else {
      str_loadcell += c;
    }
  }
  if (caliper_done && loadcell_done){
    Serial.print(str_caliper);
    Serial.print(",");
    Serial.println(str_loadcell);
    str_loadcell="";
    str_caliper = "";
    loadcell_done = false;
    caliper_done = false;
    
  }
  
}
