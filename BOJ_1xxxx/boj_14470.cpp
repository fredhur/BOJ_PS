// Title : 전자레인지 https://www.acmicpc.net/problem/14470
#include <cstdio>

int A, B, C, D, E;

class Event0
{
};
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
            return;
        }

        static_cast<typename FSM::State *>(m_state)->event(event);
    }
};

class MeatState : public Fsm<MeatState>
{
public:
    MeatState(int _temperature, int _C, int _D, int _E)
    {
        temperature = _temperature;
        fronzenUnderZero.SetC(_C);
        zeroCondition.SetD(_D);
        overZero.SetE(_E);

        if (temperature > 0)
        {
            transition(overZero);
        }
        else if (temperature < 0)
        {
            transition(fronzenUnderZero);
        }
    }
    const int GetTemperature() const
    {
        return temperature;
    }

private:
    friend Fsm;

    class State : public Fsm::State
    {
        friend Fsm;
        using Fsm::State::State;
        virtual void event(Event0) {}
        virtual void entry(){};
    };

    class FronzenUnderZero : public State
    {
    private:
        int temperatureCnt;
        int C;
        friend Fsm;
        using State::State;

        void event(Event0 d)
        {
            temperatureCnt++;
            if (temperatureCnt % C == 0)
            {
                fsm.temperature++;
            }
            if (fsm.temperature == 0)
            {
                transition(fsm.zeroCondition);
            }
        }

    public:
        void SetC(const int &_C)
        {
            temperatureCnt = 0;
            C = _C;
        }
    } fronzenUnderZero{this};

    class ZeroCondition : public State
    {
    private:
        int temperatureCnt;
        int D;
        friend Fsm;
        using State::State;

        void event(Event0 d)
        {
            temperatureCnt++;

            if (temperatureCnt == D)
            {
                transition(fsm.overZero);
            }
        }

    public:
        void SetD(const int & _D)
        {
            temperatureCnt = 0;
            D = _D;
        }
    } zeroCondition{this};

    class OverZero : public State
    {
    private:
        int temperatureCnt;
        int E;
        friend Fsm;
        using State::State;
        void event(Event0 d)
        {
            temperatureCnt++;
            if (temperatureCnt % E == 0)
            {
                fsm.temperature++;
            }

            if (fsm.temperature == B)
            {
                transition(fsm.end);
            }
        }

    public:
        void SetE(const int & _E)
        {
            temperatureCnt = 0;
            E = _E;
        }
    } overZero{this};

    class End : public State
    {
        friend Fsm;
        using State::State;
        
    } end{this};
    int temperature;
};

int main()
{

    
    scanf("%d %d %d %d %d", &A, &B, &C, &D, &E);

    MeatState meatState(A, C, D, E);

    int t = 0;
    while (meatState.GetTemperature() != B)
    {
        t++;
        meatState.handle(Event0());
    }

    printf("%d", t);
}
