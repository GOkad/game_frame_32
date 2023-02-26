#include <Arduino.h>
#include "config/.WebServerConfig.h"
#include "config/HardwareConfig.h"
#include "Engine32.h"
#include "Controller.h"

void setup() {
  Serial.begin(115200);
  Engine32::connect_to_network(WebServerConfig{});
}

void loop() {
  static Engine32 engine32(
      WebServerConfig{},
      HardwareConfig{}
  );

  engine32.event_loop();
}
