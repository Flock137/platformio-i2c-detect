#include <Arduino.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  while (!Serial) delay(10);
  
  Wire.begin();
  Wire.setClock(400000);
  
  Serial.println("\n\nI2C Scanner Starting...");
  delay(1000);
}

void loop() {
  byte error, address;
  int nDevices = 0;
  
  Serial.println("Scanning I2C bus...");
  
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    
    if (error == 0) {
      Serial.print("Device found at 0x");
      if (address < 16) Serial.print("0");
      Serial.print(address, HEX);
      Serial.println(" !");
      nDevices++;
    }
  }
  
  if (nDevices == 0) {
    Serial.println("ERROR: No I2C devices found!");
    Serial.println("Check your wiring:");
  } else {
    Serial.print("Found ");
    Serial.print(nDevices);
    Serial.println(" device(s)");
  }
  
  Serial.println("-------------------\n");
  delay(5000);
}
