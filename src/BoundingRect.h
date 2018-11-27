#ifndef BOUNDINGRECT_H_
#define BOUNDINGRECT_H_

#include <Arduino.h>

namespace m5_mytool {

class BoundingRect{
private:
    uint16_t left_{0}; /* x */
    uint16_t top_{0}; /* y */
    uint16_t width_{0};
    uint16_t height_{0};

public:
    BoundingRect() = default;
    BoundingRect(uint16_t left, uint16_t top);
    BoundingRect(uint16_t left, uint16_t top, uint16_t width, uint16_t height);
    ~BoundingRect() = default;
    BoundingRect(const BoundingRect &other) = default;
    BoundingRect &operator=(const BoundingRect &other) = default;

    uint16_t Right();
    uint16_t Bottom();
    uint16_t CenterX();
    uint16_t CenterY();
    void SetPosition(uint16_t left,uint16_t top);
    void SetSize(uint16_t width, uint16_t height);

    inline uint16_t top()const{return top_;}
    inline uint16_t left()const{return left_;}
    inline uint16_t width()const{return width_;}
    inline uint16_t height()const{return height_;}

};

} // namaspace

#endif // BOUNDINGRECT_H_