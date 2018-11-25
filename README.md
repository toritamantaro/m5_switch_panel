# m5_switch_panel

[![Powered By PlatformIO](https://img.shields.io/Powered/PlatformIO.png)](https://platformio.org/)



## Usage

```cpp

#include <M5Stack.h>

/* Subject */
#include "SwitchPanel.h"
m5_mytool::SwitchPanel sp;

/* Listener(Observer) */
#include "ToggleSwitch.h"
m5_mytool::ToggleSwitch tsw(10,20,200,10); // x, y, width, height

void setup()
{
  M5.begin();

  sp.Add(tsw); // register ToggleSwitch in SwitchPanel
  sp.Init(); // start drawing
}

void loop()
{

    // e.g. bool is_high = digitalRead(PIN_NUM)

    // make the state transition by giving a signal
    bool tsw_state = tsw.Check(is_high);

    delay(10);
}
```


