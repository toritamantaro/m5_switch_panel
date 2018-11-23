#ifndef TOGGLESWITCH_H_
#define TOGGLESWITCH_H_

#include <M5Stack.h>

#include "SwitchPanel.h"
#include "ToggleState.h"
#include "TogglePainter.h"
#include "ToggleParts.h"

namespace m5_mytool {




/**
 * ToggleSwitch is Listner for SwitchPanel(Subject) 
**/ 

// class ToggleSwitch : public Listener{
//     static const int8_t kSizeMin{10};
//     static const int8_t kPositionCounterMax{100};
//     static const int8_t kPositionCounterMin{0};

// private:
//     /* Listener */
//     // std::shared_ptr<ToggleSlider> slider_;
//     // std::shared_ptr<ToggleButton> button_;
//     // std::shared_ptr<ToggleButtonMark> mark_;

//     ToggleSlider slider_;
//     ToggleButton button_;
//     ToggleButtonMark mark_;

//     /* Subject */
//     std::unique_ptr<TogglePainter> painter_;
    
//     float_t color_ratio_{0.0}; /* 0.0 to 1.0 */
//     int8_t position_counter_{0}; /* kPositionCounterMin to kPositionCounterMax */
//     float_t position_ratio_{0.0}; /* 0.0 to 1.0 */
//     ButtonStateContext state_context_; /* switch state manager */
//     BUTTON state_; /* switch state */

//     void ProceedNextPosition(); /* update position_counter_ */ 
//     std::unique_ptr<TogglePainter> PainterMaker(int16_t top, int16_t left, int16_t width, int16_t height);

// public:
//     ToggleSwitch()=delete;
//     ToggleSwitch(int16_t top, int16_t left, int16_t width, int16_t height);

//     bool Check(bool is_high);
//     bool State()const;

//     void SetColorPalette(ColorPalette p){painter_->set_palette(p);}

// protected:
//     void update(Subject* from) override;

// };


class ToggleSwitchBase : public ListenerBase{
    static const int8_t kSizeMin{10};
    static const int8_t kPositionCounterMax{100};
    static const int8_t kPositionCounterMin{0};

private:
    /* Listener */
    // std::shared_ptr<ToggleSlider> slider_;
    // std::shared_ptr<ToggleButton> button_;
    // std::shared_ptr<ToggleButtonMark> mark_;

    ToggleSlider slider_;
    ToggleButton button_;
    ToggleButtonMark mark_;

    /* Subject */
    std::unique_ptr<TogglePainter> painter_;
    
    float_t color_ratio_{0.0}; /* 0.0 to 1.0 */
    int8_t position_counter_{0}; /* kPositionCounterMin to kPositionCounterMax */
    float_t position_ratio_{0.0}; /* 0.0 to 1.0 */
    ButtonStateContext state_context_; /* switch state manager */
    BUTTON state_; /* switch state */

    void ProceedNextPosition(); /* update position_counter_ */ 
    std::unique_ptr<TogglePainter> PainterMaker(int16_t top, int16_t left, int16_t width, int16_t height);

public:
    ToggleSwitchBase()=delete;
    ToggleSwitchBase(int16_t top, int16_t left, int16_t width, int16_t height);

    bool Check(bool is_high);
    bool State()const;
    void SetColorPalette(ColorPalette p){painter_->set_palette(p);}

protected:
    void update(Subject* from) override;

};


class ToggleSwitch : public Listener{
public:
    ToggleSwitch() = delete;
    ToggleSwitch(int16_t top, int16_t left, int16_t width, int16_t height){
        set_handler(std::make_shared<ToggleSwitchBase>(top, left, width, height));}
    bool Check(bool is_high);
    bool State()const;
    void SetColorPalette(ColorPalette p);
};


} // namaspace
#endif // TOGGLESWITCH_H_