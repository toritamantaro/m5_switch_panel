#include "ColorPalette.h"

namespace m5_mytool
{

/*
input
red, green, blue : 0 to 255
*/
uint16_t ColorPalette::RGB2Color(uint8_t red, uint8_t green, uint8_t blue)
{
    // r , b : 0 to 31
    // g : 0 to 63
    uint8_t r = map(red, 0, UINT8_MAX, 0, 31);
    uint8_t g = map(green, 0, UINT8_MAX, 0, 63);
    uint8_t b = map(blue, 0, UINT8_MAX, 0, 31);
    return (r << 11) | (g << 5) | b;
}

/*
output
rgb[0] (red)   : 0 to 255
rgb[1] (green) : 0 to 255
rgb[2] (blue)  : 0 to 255
*/
void ColorPalette::Color2RGB(uint16_t color, uint8_t rgb[])
{
    uint8_t r = color >> 11;         // valid lower 5 bit
    uint8_t g = (color >> 5) & 0x3F; // valid lower 6 bit
    uint8_t b = color & 0x1F;        // valid lower 5 bit

    rgb[0] = map(r, 0, 31, 0, UINT8_MAX);
    rgb[1] = map(g, 0, 63, 0, UINT8_MAX);
    rgb[2] = map(b, 0, 31, 0, UINT8_MAX);
}

uint16_t ColorPalette::GetGradationColor(uint16_t base_color, uint16_t target_color, float_t ratio)
{
    /* ratio : 0.0 to 1.0 */
    ratio = (ratio < 0) ? 0.0 : _min(1.0, ratio);

    uint8_t rgb_base[3];
    uint8_t rgb_targ[3];

    Color2RGB(base_color, rgb_base);
    Color2RGB(target_color, rgb_targ);

    float_t red = (float_t)(rgb_targ[0] - rgb_base[0]) * ratio + (float_t)rgb_base[0];
    float_t green = (float_t)(rgb_targ[1] - rgb_base[1]) * ratio + (float_t)rgb_base[1];
    float_t blue = (float_t)(rgb_targ[2] - rgb_base[2]) * ratio + (float_t)rgb_base[2];

    return RGB2Color((uint8_t)red, (uint8_t)green, (uint8_t)blue);
}

} // namespace m5_mytool
