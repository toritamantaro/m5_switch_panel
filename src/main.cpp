#include <Arduino.h>

/* Subject */
#include "SwitchPanel.h"
m5_mytool::SwitchPanel sp;

/* Listener(Observer) */
#include "ToggleSwitch.h"
m5_mytool::ToggleSwitch switch_a(10,20,200,10); // x, y, width, height
m5_mytool::ToggleSwitch switch_b(10,65,150,30); // x, y, width, height
m5_mytool::ToggleSwitch switch_c(10,130,200,90); // x, y, width, height

/* ColorPalette */
// #include "ColorPalette.h"

const uint8_t buttonA_GPIO = 39;
const uint8_t buttonB_GPIO = 38;
const uint8_t buttonC_GPIO = 37;

const uint8_t LedPin = 22; // LED test

void setup() {
  // Initialize the M5Stack object
  M5.begin();

  Serial.begin(115200);

  pinMode(buttonA_GPIO, INPUT);
  pinMode(buttonB_GPIO, INPUT);
  pinMode(buttonC_GPIO, INPUT);

  pinMode(LedPin, OUTPUT); // LED test

  // m5_mytool::ColorPalette plt;
  // plt.set_background(m5_mytool::ColorPalette::kGreen);
  // switch_c.SetColorPalette(plt);

  sp.Add(switch_a);
  sp.Add(switch_b);
  sp.Add(switch_c);

  sp.Init();

}

void loop() {
  // digitalRead returns LOW when M5stack button pressed.
  bool A_is_high = !digitalRead(buttonA_GPIO);
  bool B_is_high = !digitalRead(buttonB_GPIO);
  bool C_is_high = !digitalRead(buttonC_GPIO);

  // TggleSwitch returns the button state.
  bool state_A = switch_a.Check(A_is_high);
  bool state_B = switch_b.Check(B_is_high);
  bool state_C = switch_c.Check(C_is_high);

  if(state_C){ // LED test
    digitalWrite(LedPin,HIGH);
  }else{
    digitalWrite(LedPin,LOW);
  }

  delay(10);

}