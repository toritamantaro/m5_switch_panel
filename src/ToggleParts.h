#ifndef TOGGLEPARTS_H_
#define TOGGLEPARTS_H_

#include "TogglePainter.h"

namespace m5_mytool {

/**
 * ToggleParts is Listner for TogglePainter(Subject)
**/
class ToggleButton : public Listener{
protected:
    void update(Subject* from) override;

};

class ToggleButtonMark : public Listener{
protected:
    void update(Subject* from) override;

};

class ToggleSlider : public Listener{
protected:
    void update(Subject* from) override;

};

} // namespace
#endif // TOGGLEPARTS_H_