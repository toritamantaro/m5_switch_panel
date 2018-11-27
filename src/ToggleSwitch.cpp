#include "ToggleSwitch.h"

#include <Arduino.h>

namespace m5_mytool {

ToggleSwitchBase::ToggleSwitchBase(int16_t top, int16_t left, int16_t width, int16_t height) : 
    painter_{PainterMaker(top,left,width,height)}
{
    painter_->Add(slider_);
    painter_->Add(button_);
    painter_->Add(mark_);
}

std::unique_ptr<TogglePainter> ToggleSwitchBase::PainterMaker(int16_t top, int16_t left, int16_t width, int16_t height){

    height = _max(kSizeMin, height); /* height : more than kSizeMin */
    width = _max(height * 2, width); /* width : more than twice the height */

    return std::unique_ptr<TogglePainter>(new TogglePainter(top, left, width, height));
}

void ToggleSwitchBase::Update(Subject* from){

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

bool ToggleSwitchBase::State()const{
    return state_ == BUTTON::kToggleOn && position_counter_ == kPositionCounterMax;
}

bool ToggleSwitchBase::Check(bool is_high){
    state_=state_context_.Check(is_high);
    return State();
}

void ToggleSwitchBase::ProceedNextPosition(){
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

bool ToggleSwitch::State()const{
    // std::shared_ptr<ToggleSwitchBase> h = std::dynamic_pointer_cast<ToggleSwitchBase>(body());
    std::weak_ptr<ToggleSwitchBase> h = std::static_pointer_cast <ToggleSwitchBase>(body());
    return h.lock()->State();
}

bool ToggleSwitch::Check(bool is_high){
    // std::shared_ptr<ToggleSwitchBase> h = std::dynamic_pointer_cast<ToggleSwitchBase>(body());
    std::weak_ptr<ToggleSwitchBase> h = std::static_pointer_cast <ToggleSwitchBase>(body());
    return h.lock()->Check(is_high);
}

void ToggleSwitch::SetColorPalette(ColorPalette palette){
    // std::shared_ptr<ToggleSwitchBase> h = std::dynamic_pointer_cast<ToggleSwitchBase>(body());
    std::weak_ptr<ToggleSwitchBase> h = std::static_pointer_cast <ToggleSwitchBase>(body());
    h.lock()->SetColorPalette(palette);  
}


} // namespace
