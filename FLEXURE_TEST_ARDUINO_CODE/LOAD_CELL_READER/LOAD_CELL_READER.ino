
#include "HX711.h"

#define calibration_factor 14.39 //g calibrated

#define LOADCELL_DOUT_PIN  5
#define LOADCELL_SCK_PIN  4
bool last_state;
float weight = 0;
const int rx_pin = 6;

HX711 scale;

void setup() {
  Serial.begin(115200);
  pinMode(rx_pin, INPUT);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare(); //Assuming there is no weight on the scale at start up, reset the scale to 0
  last_state = digitalRead(rx_pin);
  //Serial.println("Load_LBS");
}

void loop() {
  if (last_state != digitalRead(rx_pin)) {
  last_state = digitalRead(rx_pin);
    if (last_state == HIGH) {
      weight = scale.get_units();
      Serial.println(weight, 1); //scale.get_units() returns a float
    }
  } 
}
