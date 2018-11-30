#include "TogglePainter.h"

namespace m5_mytool
{

TogglePainter::TogglePainter(int16_t top, int16_t left, int16_t width, int16_t height) : 
    sprite_{std::unique_ptr<TFT_eSprite>(new TFT_eSprite(&M5.Lcd))}
{
    rect_.SetPosition(top, left);
    rect_.SetSize(width, height);
}

TogglePainter::TogglePainter(int16_t top, int16_t left, int16_t width, int16_t height, ColorPalette palette) : 
    TogglePainter(top, left, width, height)
{
    palette_ = palette;
}

void TogglePainter::InitSprite()
{
    sprite_->setColorDepth(8);
    sprite_->setBitmapColor(palette_.primary(), palette_.background());
    sprite_->createSprite(rect_.width(), rect_.height());
    sprite_->fillSprite(palette_.background());
}

void TogglePainter::DrawLisners()
{

    /* create sprite before draw */
    InitSprite();

    /* call Listeners handler */
    Notify();

    /* push the sprite */
    sprite_->pushSprite(rect_.left(), rect_.top());

    // delay(1000);

    /* delete the sprite */
    sprite_->deleteSprite();
}

} // namespace m5_mytool
