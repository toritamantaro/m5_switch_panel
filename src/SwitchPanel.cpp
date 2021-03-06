#include "SwitchPanel.h"

namespace m5_mytool
{

const uint32_t DEFAULT_STACK_SIZE = 4096;

void NotifyListenersViaSubject(void *args)
{
    SwitchPanel *sp = reinterpret_cast<SwitchPanel *>(args);

    for (;;){
        sp->NotifyListeners();
        delay(15);
        // delay(1000);
    }
}

void CyclicVariation(void *args)
{
    uint16_t partition = 100;
    int16_t c = 0;
    SwitchPanel *sp = reinterpret_cast<SwitchPanel *>(args);
    for (;;){
        c = (c + 1) % partition;
        float_t f = sin(c * 2 * PI / (float_t)partition);
        sp->set_variation_value(f);
        delay(25);
    }
}

/* ---------------------------------------------------------------------- */

void SwitchPanel::Init()
{

    xTaskCreate(
        NotifyListenersViaSubject,   /* Function to implement the task */
        "NotifyListenersViaSubject", /* Name of the task */
        DEFAULT_STACK_SIZE,          /* Stack size */
        this,                        /* Task input parameter */
        1,                           /* Priority of the task */
        NULL);                       /* Task handle. */

    xTaskCreate(
        CyclicVariation,    /* Function to implement the task */
        "CyclicVariation",  /* Name of the task */
        DEFAULT_STACK_SIZE, /* Stack size */
        this,               /* Task input parameter */
        2,                  /* Priority of the task */
        NULL);              /* Task handle. */
}

} // namespace m5_mytool