#include "ToggleParts.h"

namespace m5_mytool {

void ToggleButton::update(Subject* from){

    // Serial.println(" I am Button:");

    TogglePainter* subject = static_cast<TogglePainter*>(from);
    bool is_on = subject->toggle_is_on();
    float_t color_ratio=subject->color_ratio(); /* 0.0 to 1.0 */
    float_t position_ratio=subject->position_ratio(); /* 0.0 to 1.0 */
    ColorPalette* palette = subject->palette_pt();
    BoundingRect* rect = subject->rect_pt();
    TFT_eSprite* sprite = subject->sprite_pt();

    // Serial.println(position_ratio);

    uint16_t height = rect->height();
    uint16_t width = rect->width();
    height = (height % 2) ? height : height - 1 ;
    uint16_t r = height/2;
    uint16_t move_range = width - ( 2 * r + 1 );
    uint16_t x = r + move_range*position_ratio;
    uint16_t y = height/2;
    uint16_t color = palette->foreground();

    if(position_ratio == 0.0){
        if(is_on){
            color = palette->GetGradationColor(color_ratio);
        }
    }

    uint16_t gap=0;
    sprite->fillCircle(x, y, r-gap, color);

}

void ToggleButtonMark::update(Subject* from){

    TogglePainter* subject = static_cast<TogglePainter*>(from);
    bool is_on = subject->toggle_is_on();
    float_t color_ratio=subject->color_ratio(); /* 0.0 to 1.0 */
    float_t position_ratio=subject->position_ratio(); /* 0.0 to 1.0 */
    ColorPalette* palette = subject->palette_pt();
    BoundingRect* rect = subject->rect_pt();
    TFT_eSprite* sprite = subject->sprite_pt();

    uint16_t height = rect->height();
    uint16_t width = rect->width();
    height = (height % 2) ? height : height - 1 ;
    uint16_t r = height/2;
    uint16_t move_range = width - (2*r+1);
    uint16_t x = r + move_range*position_ratio;
    uint16_t y = height/2;

    /* paramaters for mark of [I] and [O] */
    uint16_t rect_w = ((float_t)height)*0.15;
    uint16_t rect_h = ((float_t)height)*0.6;
    uint16_t rect_x = x - rect_w/2;
    uint16_t rect_y = y - rect_h/2;

    uint16_t color = palette->primary();

    if(position_ratio == 0.0 || position_ratio == 1.0){
        if(is_on){
            /* mark of [I] */
            color = palette->GetGradationColor(1.0 - color_ratio);
            sprite->fillCircle(x,y, rect_h*0.65, palette->foreground());
            sprite->fillRect(rect_x, rect_y, rect_w, rect_h, color);
        }else{
            /* mark of [O] */
            sprite->fillCircle(x, y, rect_h*0.5, palette->secondary());
            sprite->fillCircle(x, y, rect_h*0.35, palette->foreground());
        }
    }

}

void ToggleSlider::update(Subject* from){
    TogglePainter* subject = static_cast<TogglePainter*>(from);

    bool is_on = subject->toggle_is_on();
    float_t color_ratio=subject->color_ratio(); /* 0.0 to 1.0 */
    float_t position_ratio=subject->position_ratio(); /* 0.0 to 1.0 */
    ColorPalette* palette = subject->palette_pt();
    BoundingRect* rect = subject->rect_pt();
    TFT_eSprite* sprite = subject->sprite_pt();

    uint16_t height = rect->height();
    uint16_t width = rect->width();
    height = (height % 2) ? height : height - 1 ;
    uint16_t r = height/2;
    uint16_t move_range = width - (2*r+1);
    uint16_t x = r;
    uint16_t y = height/2;

    uint16_t color = palette->secondary();

    if(position_ratio == 0.0){
        if(is_on){
            color = palette->primary();
        }
    }

    sprite->fillRect(x, 0, move_range, height, color);
    sprite->fillCircle(x, y, r, color);
    sprite->fillCircle(x + move_range, y, r, color);

}


} // namespace