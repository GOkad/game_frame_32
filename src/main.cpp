#include <Arduino.h>
#include "config/.WebServerConfig.h"
#include "Engine32.h"


TaskHandle_t core_0_th;

void core_0_main(void* parameter)
{
  WebServerConfig config{};
  Engine32 engine32(config);
  while(true)
  {
  }
}

void setup() {
  Serial.begin(115200);

  xTaskCreatePinnedToCore(
    core_0_main,   // Task function.
    "core_0_task", // name of task.
    10000,         // Stack size of task
    NULL,          // parameter of the task
    1,             // priority of the task
    &core_0_th,    // Task handle to keep track of created task
    1              // pin task to core 0
  );
}

void loop() {}
