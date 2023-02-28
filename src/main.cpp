#include <Arduino.h>
#include "config/.WebServerConfig.h"
#include "core/Screen.h"
#include "Engine32.h"

Engine32 engine32(WebServerConfig{});

void setup() {
  Serial.begin(115200);
  engine32.register_event(CallbackEvents::DRAW,[](){
    // Draw frame
    
  });
}

void loop() {
  delay(500);
}
