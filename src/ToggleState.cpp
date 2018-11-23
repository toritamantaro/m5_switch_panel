#include "ToggleState.h"

namespace m5_mytool{

ButtonStateContext::ButtonStateContext() : 
    state_{ToggleOff()} {}

/**
 *  BUTTON Check(bool is_high)
 *  transit the state by giving a signal
**/
BUTTON ButtonStateContext::Check(bool is_high){
    state_->Read(is_high, this);
    return state_->GetStateEnum();
}


ButtonState *ButtonStateContext::ToggleOff() const{
    static ToggleOffState state;
    return &state;
}

ButtonState *ButtonStateContext::ToggleRising() const{
    static ToggleRisingState state;
    return &state;
}

ButtonState *ButtonStateContext::ToggleOn() const{
    static ToggleOnState state;
    return &state;
}

ButtonState *ButtonStateContext::ToggleFalling() const{
    static ToggleFallingState state;
    return &state;
}

/* ---------------------------------------------------------------------- */

void ToggleOffState::Read(bool is_high, ButtonStateContext *ctx){
    if (is_high){
        ctx->set_state(ctx->ToggleRising()); /* transit the state */
    }
}

void ToggleRisingState::Read(bool is_high, ButtonStateContext *ctx){
    if (!is_high){
        ctx->set_state(ctx->ToggleOn()); /* transit the state */ 
    }
}

void ToggleOnState::Read(bool is_high, ButtonStateContext *ctx){
    if (is_high){
        ctx->set_state(ctx->ToggleFalling()); /* transit the state */
    }
}

void ToggleFallingState::Read(bool is_high, ButtonStateContext *ctx){
    if (!is_high){
        ctx->set_state(ctx->ToggleOff()); /* transit the state */ 
    }
}


} // namespace