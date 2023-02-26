#include <Arduino.h>
#include "config/.WebServerConfig.h"
#include "Engine32.h"

void setup() {
  Serial.begin(115200);
  Serial.println("");
  
}

void loop() {
  static Engine32 engine32(WebServerConfig{});
}
