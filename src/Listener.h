
#ifndef LISTENER_H_
#define LISTENER_H_

#include <memory>
#include <vector>

namespace m5_mytool
{

class Subject;

class ListenerBody
{
    friend class Subject;

  public:
    virtual ~ListenerBody() = default;

  protected:
    virtual void Update(Subject *sub) = 0; /* handler */
};

class Listener
{
    friend class Subject;

  private:
    std::shared_ptr<ListenerBody> body_;

  protected:
    void set_body(std::shared_ptr<ListenerBody> body) { body_ = body; }
    std::shared_ptr<ListenerBody> body() const { return body_; }

  public:
    virtual ~Listener() = default;
};

} // namespace m5_mytool
#endif // LISTENER_H_