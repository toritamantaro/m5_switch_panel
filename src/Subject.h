#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <memory>
#include <vector>

#include "Listener.h"

namespace m5_mytool {

class Subject{
private:
    std::vector<std::weak_ptr<ListenerBody>> bodies_;

public:
    /* register the Listener */
    void Add(Listener& listener);

    /* deregister the Listener */
    void Detete(Listener& listener);

    /* sweep unreferenced Listeners */
    void Sweep();

protected:
    /* call Listeners handler */
    void Notify();

};





} // namespace
#endif // SUBJECT_H_