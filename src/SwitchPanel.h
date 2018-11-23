
#ifndef SWITCHPANEL_H_
#define SWITCHPANEL_H_

#include <M5Stack.h>

#include "Subject.h"

namespace m5_mytool{

/**
 * SwitchPanel is Subject for ToggleSwitch(Listner)
**/ 
class SwitchPanel : public Subject{
private:
    float_t variation_value_;

public:
    SwitchPanel() = default;
    ~SwitchPanel() = default;

    void init(void);

    void NotifyListeners(){notify();}

    float_t variation_value()const{return variation_value_;}
    void set_variation_value(float_t f){variation_value_=f;}

};


} // namespace
#endif // SWITCHPANEL_H_