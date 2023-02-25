#include <Arduino.h>
#include "config/.WebServerConfig.h"
#include "config/HardwareConfig.h"
#include "Engine32.h"


TaskHandle_t core_1_th;
WebServerConfig config{};

void core_1_main(void* parameter)
{
  
  while(true)
  {
    Serial.println("Core 1 task;");
    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  // Engine32::connect_to_network(config);

  /**
   * Initiate Core 1 Task
   * and pin to core: 1
   */
  xTaskCreatePinnedToCore(
    core_1_main,   // Task function.
    "core_1_task", // name of task.
    10000,         // Stack size of task
    NULL,          // parameter of the task
    1,             // priority of the task
    &core_1_th,    // Task handle to keep track of created task
    1              // pin task to core 0
  );
}

void loop() {
  static Engine32 engine32(config);
}
