// Title : ビ太郎と IOI (Bitaro and IOI) https://www.acmicpc.net/problem/24073
#include <cstdio>
template <class FSM>
class Fsm
{
protected:
    // Base class for all states
    class State
    {
    public:
        State(FSM *fsm) : fsm(*fsm) {}
        virtual ~State() {}

    private:
        friend Fsm;
        virtual void exit() {}

    protected:
        FSM &fsm;

        // Convenience method
        template <class S, class... Types>
        void transition(S &nextState, Types... args) { fsm.Fsm<FSM>::transition(nextState, args...); }
    };

    template <class S, class... Types>
    void transition(S &nextState, Types... args)
    {
        if (m_state)
            m_state->exit();
        static_cast<FSM *>(this)->onTransition(nextState);
        m_state = &nextState;
        nextState.entry(args...);
        static_cast<FSM *>(this)->afterTransition();
    }

    // Call this from derived class destructor if needed. We cannot
    // make this in our destructor, because the states are already
    // destoyed when it runs.
    void destroy()
    {
        if (m_state)
            m_state->exit();
        m_state = nullptr;
    }

private:
    State *m_state = nullptr;

    // Prevent compile error if derived class does not have its own onTransition() method
    void onTransition(State &nextState) {}
    void afterTransition() {}

public:
    State *state() const { return m_state; }

    template <typename EV>
    void handle(EV event)
    {
        if (!m_state)
        {
        }
        static_cast<typename FSM::State *>(m_state)->event(event);
    }
};

class EventCharI
{
};
class EventCharO
{
};

class IOIFsm : public Fsm<IOIFsm>
{
public:
    IOIFsm()
    {
        transition(idle);
        isSuccess = false;
    }
    ~IOIFsm() = default;
    bool GetSuccess() const
    {
        return isSuccess;
    }

private:
    friend Fsm;
    class State : public Fsm::State
    {
        friend Fsm;
        using Fsm::State::State;
        virtual void event(EventCharI) {}
        virtual void event(EventCharO) {}
    };

    class Idle : public State
    {
        friend Fsm;
        using State::State;

        void entry() {}
        void event(EventCharI)
        {
            transition(fsm.iState);
        }

    } idle{this};
    class IState : public State
    {
        friend Fsm;
        using State::State;
        void entry() {}
        void event(EventCharO)
        {
            transition(fsm.oState);
        }
    } iState{this};

    class OState : public State
    {
        friend Fsm;
        using State::State;
        void entry() {}
        void event(EventCharI)
        {
            transition(fsm.finalState);
        }
    } oState{this};
    class FinalState : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.isSuccess = true;
        }
    } finalState{this};
    bool isSuccess;
};
int main()
{
    IOIFsm ioIFsm;
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char ch;
        scanf(" %1c", &ch);
        if (ch == 'I')
        {
            ioIFsm.handle(EventCharI());
        }
        else if (ch == 'O')
        {
            ioIFsm.handle(EventCharO());
        }
    }

    puts(ioIFsm.GetSuccess() == true ? "Yes" : "No");
}