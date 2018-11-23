
#ifndef LISTENER_H_
#define LISTENER_H_

namespace m5_mytool {

#include <memory>
#include <vector>

class Subject;

class ListenerBase {
    friend class Subject;
public:
    virtual ~ListenerBase() = default;
protected:
    virtual void update(Subject* sub) = 0; /* handler */

};

class Listener{
    friend class Subject;
private:
    std::shared_ptr<ListenerBase> handler_;
protected:

    void set_handler(std::shared_ptr<ListenerBase> handler){handler_ = handler;}
    std::shared_ptr<ListenerBase> handler() const{return handler_;}

public:
    virtual ~Listener() = default;
};

} // namespace
#endif // LISTENER_H_