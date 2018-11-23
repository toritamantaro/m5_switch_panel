#ifndef COLORPALETTE_H_
#define COLORPALETTE_H_

#include <Arduino.h>

namespace m5_mytool {

class ColorPalette{

public:
    static const uint16_t kBlack{0x0000}; // 0, 0, 0
    static const uint16_t kWhite{0xFFFF}; // 255, 255, 255
    static const uint16_t kRed{0xF800}; // 255, 0, 0
    static const uint16_t kGreen{0x07E0}; // 0, 255, 
    static const uint16_t kBlue{0x001F}; // 0, 0, 255
    static const uint16_t kPink{0xFB3B}; // 255, 100, 220
    static const uint16_t kLightRed{0xFB2C}; // 255, 100, 100
    static const uint16_t kLightGreen{0x3706}; // 50, 255, 50
    static const uint16_t kLightBlue{0x2C7F}; // 40, 140, 255
    static const uint16_t kLightGrey{0xC618}; // 192, 192, 192
    static const uint16_t kDarkGray{0x632C}; // 100, 100, 100

private:
    // uint16_t primary_{kPink};
    // uint16_t primary_{kGreen};
    uint16_t primary_{kBlue};
    // uint16_t primary_{kLightBlue};
    // uint16_t secondary_{kLightGrey};
    // uint16_t secondary_{kRed};
    uint16_t secondary_{kPink};
    uint16_t foreground_{kWhite};
    uint16_t background_{kBlack};
    uint16_t transparent_{kBlack};

public:
    ColorPalette() = default;
    ~ColorPalette() = default;

    static uint16_t RGB2Color(uint8_t red, uint8_t green, uint8_t blue);
    static void Color2RGB(uint16_t color, uint8_t rgb[]);
    static uint16_t GetGradationColor(uint16_t base_color, uint16_t mark_color, float_t ratio);
    uint16_t GetGradationColor(float_t ratio){return GetGradationColor(foreground_, primary_, ratio);}

    uint16_t primary()const{return primary_;}
    uint16_t secondary()const{return secondary_;}
    uint16_t foreground()const{return foreground_;}
    uint16_t background()const{return background_;}
    uint16_t transparent()const{return transparent_;}

    void set_primary(uint16_t c){primary_=c;}
    void set_secondary(uint16_t c){secondary_=c;}
    void set_foreground(uint16_t c){foreground_=c;}
    void set_background(uint16_t c){background_=c;}
    void set_transparent(uint16_t c){transparent_=c;}

};

} // namaspace


#endif // COLORPALETTE_H_