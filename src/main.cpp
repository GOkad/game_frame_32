#include <Arduino.h>
#include "config/.WebServerConfig.h"
#include "Engine32.h"

Engine32 engine32(WebServerConfig{});


void setup() {
  Serial.begin(115200);
  engine32.set_frame_cb([](){

  });
}

void loop() {
}
