
#ifndef LISTENER_H_
#define LISTENER_H_

namespace m5_mytool {

class Subject;

class Listener{
    friend class Subject;

public:
    virtual ~Listener() = default;
    virtual void update(Subject* sub) = 0;
};

} // namespace
#endif // LISTENER_H_