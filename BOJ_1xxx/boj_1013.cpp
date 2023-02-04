#include <cstdio>
enum class STATE
{
    IDLE,
    A,
    B,
    C,
    D,
    E,
    F,
    ERROR
};
class Event0
{
};
class Event1
{
};
class EventInit{};
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

    void destroy()
    {
        if (m_state)
            m_state->exit();
        m_state = nullptr;
    }

private:
    State *m_state = nullptr;

    void onTransition(State &nextState) {}
    void afterTransition() {}

public:
    State *state() const { return m_state; }
    // using F = typename FSM::State*;
    template <typename EV>
    void handle(EV event)
    {
        if (!m_state)
        {
        }
        // throw std::domain_error(__func__);
        static_cast<typename FSM::State *>(m_state)->event(event);
    }
};

class Machine : public Fsm<Machine>
{
public:
    STATE getState()
    {
        return state;
    }
    Machine()
    {
        Machine::state = STATE::IDLE;
        transition(idle);
    }

private:
    friend Fsm;
    STATE state;
    class State : public Fsm::State
    {
    public:
        friend Fsm;
        using Fsm::State::State;
        virtual void event(EventInit)
        {
            transition(fsm.idle);
        }
        virtual void event(Event0) {}
        virtual void event(Event1) {}
        virtual void entry() {}
    };
    class Idle : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.state = STATE::IDLE;
        }
        void event(Event0 e)
        {
            transition(fsm.g);
        }
        void event(Event1 e)
        {
            transition(fsm.a);
        }
    } idle{this};
    class A : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.state = STATE::A;
        }
        void event(Event0 e)
        {
            transition(fsm.b);
        }
        void event(Event1 e)
        {
            transition(fsm.error);
        }

    } a{this};
    class B : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.state = STATE::B;
        }
        void event(Event0 e)
        {
            transition(fsm.c);
        }
        void event(Event1 e)
        {
            transition(fsm.error);
        }
    } b{this};
    class C : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.state = STATE::C;
        }
        void event(Event0 e)
        {
            transition(fsm.c);
        }
        void event(Event1 e)
        {
            transition(fsm.d);
        }
    } c{this};
    class D : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.state = STATE::D;
        }
        void event(Event0 e)
        {
            transition(fsm.g);
        }
        void event(Event1 e)
        {
            transition(fsm.e);
        }
    } d{this};
    class E : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {

            fsm.state = STATE::E;
        }
        void event(Event0 e)
        {
            transition(fsm.f);
        }
        void event(Event1 e)
        {
            transition(fsm.e);
        }
    } e{this};
    class F : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {

            fsm.state = STATE::F;
        }
        void event(Event0 e)
        {
            transition(fsm.c);
        }
        void event(Event1 e)
        {
            transition(fsm.idle);
        }
    } f{this};
    class G : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.state = STATE::F;
        }
        void event(Event0 e)
        {
            transition(fsm.error);
        }
        void event(Event1 e)
        {
            transition(fsm.idle);
        }
    } g{this};
    class Error : public State
    {
        friend Fsm;
        using State::State;
        void entry()
        {
            fsm.state = STATE::ERROR;
        }

    } error{this};
};

int main()
{

    

    int N;
    Machine machine;
    scanf("%d", &N);
    char input[203];
    while(N--)
    {
        
        machine.handle(EventInit{});
        scanf(" %s", input);

        for(int i=0; input[i]; i++)
        {
            if(input[i] == '0')
            {
                machine.handle(Event0{});
            }
            else 
            {
                machine.handle(Event1{});
            }
        }
        if(machine.getState() == STATE::D || machine.getState() == STATE::E || machine.getState() == STATE::IDLE)
        {
            puts("YES");
        }
        else 
        {
            puts("NO");
        }
    }


}