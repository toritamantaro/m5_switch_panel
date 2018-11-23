#include <Arduino.h>
#include "ToggleSwitch.h"

namespace m5_mytool {

ToggleSwitch::ToggleSwitch(int16_t top, int16_t left, int16_t width, int16_t height) : 
    slider_{std::make_shared<ToggleSlider>()},
    button_{std::make_shared<ToggleButton>()},
    mark_{std::make_shared<ToggleButtonMark>()},
    painter_{PainterMaker(top,left,width,height)}
{

    painter_->add_listener(slider_);
    painter_->add_listener(button_);
    painter_->add_listener(mark_);

}

std::unique_ptr<TogglePainter> ToggleSwitch::PainterMaker(int16_t top, int16_t left, int16_t width, int16_t height){

    height = _max(kSizeMin, height); /* height : more than kSizeMin */
    width = _max(height * 2, width); /* width : more than twice the height */

    return std::unique_ptr<TogglePainter>(new TogglePainter(top, left, width, height));
}

void ToggleSwitch::update(Subject* from){

    color_ratio_ = (static_cast<SwitchPanel*>(from)->variation_value() + 1.0)/2.0;

    /* update position_counter_ and position_ratio_ */
    ProceedNextPosition();

    /* pass update data to TogglePainter(Subject) */
    painter_->set_position_ratio(position_ratio_);
    painter_->set_color_ratio(color_ratio_);
    painter_->set_toggle_is_on(state_ == BUTTON::kToggleOn ? true : false);

    /* notify ToggleParts(Listener) via TogglePainter(Subject) */
    painter_->DrawLisners();

}

bool ToggleSwitch::State()const{
    return state_ == BUTTON::kToggleOn && position_counter_ == kPositionCounterMax;
}

bool ToggleSwitch::Check(bool is_high){
    state_=state_context_.Check(is_high);
    return State();
}

void ToggleSwitch::ProceedNextPosition(){
    //Serial.println(position_counter_);

    /* update : position_counter_ */
    int16_t delta = 5;
    if(state_ == BUTTON::kToggleOn || state_ == BUTTON::kToggleRising){
        if(position_counter_ < kPositionCounterMax){
            position_counter_ = _min(position_counter_ + delta, kPositionCounterMax);
        }
    }else{
        if(position_counter_ > kPositionCounterMin){
            position_counter_ = _max(kPositionCounterMin, position_counter_ - delta);
        }
    }   

    /* update : position_ratio_ */
    float_t range = kPositionCounterMax - kPositionCounterMin;
    position_ratio_ = (cos(position_counter_ * PI / range) + 1.0)/2.0; /* 0.0 to 1.0 */

}


} // namespace
