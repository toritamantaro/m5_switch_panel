#ifndef TOGGLEPARTS_H_
#define TOGGLEPARTS_H_

#include "TogglePainter.h"

namespace m5_mytool {

/**
 * ToggleParts is Listner for TogglePainter(Subject)
**/

class ToggleButtonBase : public ListenerBase{
protected:
    void update(Subject* from) override;
};
class ToggleButton : public Listener{
public:
    ToggleButton(){set_handler(std::make_shared<ToggleButtonBase>());}
};

class ToggleButtonMarkBase : public ListenerBase{
protected:
    void update(Subject* from) override;
};

class ToggleButtonMark : public Listener{
public:
    ToggleButtonMark(){set_handler(std::make_shared<ToggleButtonMarkBase>());}
};


class ToggleSliderBase : public ListenerBase{
protected:
    void update(Subject* from) override;

};

class ToggleSlider : public Listener{
public:
    ToggleSlider(){set_handler(std::make_shared<ToggleSliderBase>());}

};


} // namespace
#endif // TOGGLEPARTS_H_