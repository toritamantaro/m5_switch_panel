#ifndef TOGGLESTATE_H_
#define TOGGLESTATE_H_

namespace m5_mytool{

enum class BUTTON{
    kToggleOff,       /* toggle button is OFF */
    kToggleRising,    /* toggle button is Rising */
    kToggleOn,        /* toggle button is ON */
    kToggleFalling    /* toggle button is Falling */
};

class ButtonState; 

/**
 *   class ButtonStateContext
 *   manage toggle button state
**/
class ButtonStateContext{
  public:
    ButtonStateContext();
    ~ButtonStateContext() = default;

    BUTTON Check(bool is_high); /* Transit the state by giving a signal */

    /* Getter-Setter */
    void set_state(ButtonState *next) { state_ = next; }

    ButtonState *ToggleOff() const;
    ButtonState *ToggleRising() const;
    ButtonState *ToggleOn() const;
    ButtonState *ToggleFalling() const;

  private:
    ButtonState *state_;
};

/* ---------------------------------------------------------------------- */

class ButtonState{
    friend class ButtonStateContext;
  public:
    ButtonState()=default;
    virtual ~ButtonState()=default;
  protected:
    virtual void Read(bool is_high, ButtonStateContext *ctx) = 0;
    virtual BUTTON GetStateEnum() = 0;
};

/* OFF state */
class ToggleOffState : public ButtonState{
  public:
    ToggleOffState() = default;
    ~ToggleOffState() = default;
  protected:
    void Read(bool is_high, ButtonStateContext *ctx) override;
    BUTTON GetStateEnum() override { return BUTTON::kToggleOff; }
};

/* Rising state */
class ToggleRisingState : public ButtonState{
  public:
    ToggleRisingState() = default;
    ~ToggleRisingState() = default;
  protected:
    void Read(bool is_high, ButtonStateContext *ctx) override;
    BUTTON GetStateEnum() override { return BUTTON::kToggleRising; }
};

/* ON state */
class ToggleOnState : public ButtonState{
  public:
    ToggleOnState() = default;
    ~ToggleOnState() = default;
  protected:
    void Read(bool is_high, ButtonStateContext *ctx) override;
    BUTTON GetStateEnum() override { return BUTTON::kToggleOn; }
};

/* Falling state */
class ToggleFallingState : public ButtonState{
  public:
    ToggleFallingState() = default;
    ~ToggleFallingState() = default;
  protected:
    void Read(bool is_high, ButtonStateContext *ctx) override;
    BUTTON GetStateEnum() override { return BUTTON::kToggleFalling; }
};

} // namespace

#endif // TOGGLESTATE_H_