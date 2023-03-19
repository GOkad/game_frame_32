#include <Arduino.h>
#include "config/.WebServerConfig.h"
#include "core/Component.h"
#include "Engine32.h"

Engine32 engine32(WebServerConfig{});

void setup() {
  Serial.begin(115200);
  engine32.register_event(CallbackEvents::DRAW,[](){
    
    // Calculations for each frame
    const std::uint8_t cell_size = 50;
    const float grid_width = random(5,10);
    const float grid_height = random(5,10);

    for(int y = 0; y < grid_height; y++ )
    {
      bool color_flag = ( y%2 == 0 );
      for(int x = 0; x < grid_width; x++ )
      {
        color_flag = !color_flag;
        Component rect(ComponentTypes::RECTANGLE);
        rect.set_position(x*cell_size, y*cell_size);
        rect.set_size(cell_size, cell_size);
        rect.set_color(color_flag ? Colors::GREEN : Colors::RED);
        engine32.add_component(rect.to_string(), false);
      }
    }
    
  });
}

void loop() {}
