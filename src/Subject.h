#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <memory>
#include <vector>

#include "Listener.h"

namespace m5_mytool {

class Subject{
private:

std::vector<std::weak_ptr<ListenerBase>> lbs_;

public:
    /* register the Listener */
    // void add_listener(std::shared_ptr<Listener> lsn);
    void add_listener(Listener& l);
    /* deregister the Listener */
    // void detete_listener(std::shared_ptr<Listener> lsn);
    void detete_listener(Listener& l);
    /* sweep unreferenced Listeners */
    void sweep();

protected:
    /* call Listeners handler */
    void notify();

};

} // namespace
#endif // SUBJECT_H_