#ifndef TOGGLEPAINTER_H_
#define TOGGLEPAINTER_H_

#include <M5Stack.h>

#include "Subject.h"
#include "BoundingRect.h"
#include "ColorPalette.h"

namespace m5_mytool {

/**
 * TogglePainter is Subject for ToggleParts(Listner)
**/
class TogglePainter : public Subject{

    float_t color_ratio_; /* 0.0 to 1.0 */
    float_t position_ratio_; /* 0.0 to 1.0 */
    bool toggle_is_on_;
    BoundingRect rect_;
    ColorPalette palette_;
    std::unique_ptr<TFT_eSprite> sprite_;

public:
    TogglePainter()=delete;
    TogglePainter(int16_t top, int16_t left, int16_t width, int16_t height);
    TogglePainter(int16_t top, int16_t left, int16_t width, int16_t height, ColorPalette palette);

    void InitSprite();
    void DrawLisners();

    float_t color_ratio()const{return color_ratio_;}
    float_t position_ratio()const{return position_ratio_;}
    bool toggle_is_on()const{return toggle_is_on_;}

    void set_color_ratio(float_t f){color_ratio_=f;}
    void set_position_ratio(float_t f){position_ratio_=f;}
    void set_toggle_is_on(bool is_on){toggle_is_on_=is_on;}
    void set_rect(BoundingRect r){rect_=r;}
    void set_palette(ColorPalette p){palette_=p;}

    ColorPalette* palette_pt(){return &palette_;}
    BoundingRect* rect_pt(){return &rect_;}

    TFT_eSprite* sprite_pt(){return sprite_.get();}
};

} // namespace
#endif // TOGGLEPAINTER_H_
