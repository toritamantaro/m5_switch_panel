#include "BoundingRect.h"

namespace m5_mytool
{

BoundingRect::BoundingRect(uint16_t left, uint16_t top) : BoundingRect{left, top, 0, 0}
{
    /* nothing */
}

BoundingRect::BoundingRect(uint16_t left, uint16_t top, uint16_t width, uint16_t height) : left_{left},
                                                                                           top_{top},
                                                                                           width_{width},
                                                                                           height_{height}
{
    /* nothing */
}

uint16_t BoundingRect::Right() { return left_ + width_; }
uint16_t BoundingRect::Bottom() { return top_ + height_; }
uint16_t BoundingRect::CenterX() { return left_ + width_ / 2; }
uint16_t BoundingRect::CenterY() { return top_ + height_ / 2; }

void BoundingRect::SetPosition(uint16_t left, uint16_t top)
{
    left_ = left;
    top_ = top;
}

void BoundingRect::SetSize(uint16_t width, uint16_t height)
{
    width_ = width;
    height_ = height;
}

} // namespace m5_mytool
