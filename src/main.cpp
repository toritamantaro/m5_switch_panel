#include <Arduino.h>

#include "SwitchPanel.h"
m5_mytool::SwitchPanel sp;

#include "ToggleSwitch.h"
std::shared_ptr<m5_mytool::ToggleSwitch> switch_a =
  std::make_shared<m5_mytool::ToggleSwitch>(10,20,200,10);
std::shared_ptr<m5_mytool::ToggleSwitch> switch_b =
  std::make_shared<m5_mytool::ToggleSwitch>(10,65,150,30);

// std::shared_ptr<m5_mytool::ToggleSwitch> switch_c;
std::shared_ptr<m5_mytool::ToggleSwitch> switch_c =
  std::make_shared<m5_mytool::ToggleSwitch>(10,130,200,90);

#include "ColorPalette.h"

const uint8_t buttonA_GPIO = 39;
const uint8_t buttonB_GPIO = 38;
const uint8_t buttonC_GPIO = 37;



void setup() {

  // m5_mytool::ColorPalette plt;
  // plt.set_background(m5_mytool::ColorPalette::kGreen);
  // switch_c->SetColorPalette(plt);


  Serial.begin(115200);

  pinMode(buttonA_GPIO, INPUT);
  pinMode(buttonB_GPIO, INPUT);
  pinMode(buttonC_GPIO, INPUT);

  // Initialize the M5Stack object
  M5.begin();

  sp.add_listener(switch_a);
  sp.add_listener(switch_b);
  sp.add_listener(switch_c);

  sp.init();

}

void loop() {

  // digitalRead return LOW when M5stack button pressed.
  bool A_is_high = !digitalRead(buttonA_GPIO);
  bool B_is_high = !digitalRead(buttonB_GPIO);
  bool C_is_high = !digitalRead(buttonC_GPIO);

  // TggleSwitch return the button state.
  bool state_A = switch_a->Check(A_is_high);
  bool state_B = switch_b->Check(B_is_high);
  bool state_C = switch_c->Check(C_is_high);

  //Serial.println(state_A);

  delay(10);



}