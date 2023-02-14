#include <cstdio>


enum class STATE
{
	NOTREGISTER,
	REGISTER,
	FLUSH
};
class HumanEvent {};
class NoHumanEvent {};
template <class FSM>
class Fsm
{
protected:
	// Base class for all states
	class State {
	public:
		State(FSM* fsm) : fsm(*fsm) {}
		virtual ~State() {}
	private:
		friend Fsm;
		virtual void exit() {}

	protected:
		FSM& fsm;

		// Convenience method
		template<class S, class ... Types>
		void transition(S& nextState, Types... args) { fsm.Fsm<FSM>::transition(nextState, args...); }
	};

	template<class S, class ... Types>
	void transition(S& nextState, Types... args) {
		if (m_state)
			m_state->exit();
		static_cast<FSM*>(this)->onTransition(nextState);
		m_state = &nextState;
		nextState.entry(args...);
		static_cast<FSM*>(this)->afterTransition();
	}

	void destroy() {
		if (m_state)
			m_state->exit();
		m_state = nullptr;
	}

private:
	State* m_state = nullptr;


	void onTransition(State& nextState) {}
	void afterTransition() {}

public:
	State* state() const { return m_state; }
	//using F = typename FSM::State*;
	template <typename EV>
	void handle(EV event) {
		if (!m_state) {}
		//throw std::domain_error(__func__);
		static_cast<typename FSM::State*>(m_state)->event(event);
	}
};

class UrinalMachine : public Fsm<UrinalMachine>
{
public:
	STATE getState()
	{
		return state;
	}
	int getFlushCnt() const
	{
		return flushCnt;
	}
	void SetTimeCnt(int& t)
	{
		timeCnt = t;

	}
	UrinalMachine()
	{
		state = STATE::NOTREGISTER;
		transition(notRegister);
		Klimit = 0, Llimit = 0;
		flushCnt = 0;
	}
	void SetKAndL(const int& k, const int& l)
	{
		Klimit = k;
		Llimit = l;
	}
private:
	int timeCnt;
	void onTransition(State& nextState)
	{
		//std::cout << "onTrnasition to " << typeid(nextState).name() << std::endl;
	}
	friend Fsm;
	STATE state;
	int Klimit;
	int Llimit;
	class State :public Fsm::State
	{
	public:
		friend Fsm;
		using Fsm::State::State;
		virtual void event(HumanEvent) {}
		virtual void event(NoHumanEvent) {}
	};
	class NotRegister : public State
	{
		friend Fsm; using State::State;
		int k;
		void entry()
		{
			k = 0;
		//	std::cout << "curret " << typeid(*this).name() << std::endl;
			fsm.state = STATE::NOTREGISTER;
		}
		void event(NoHumanEvent nohumanEvent)
		{
			k = 0;
		}
		void event(HumanEvent humanEvent)
		{
			k++;

			if (k >= fsm.Klimit)
			{
				transition(fsm.registered);
			}
		}
	}notRegister{ this };
	class Registered : public State
	{
		friend Fsm; using State::State;
		int l;
		void entry()
		{
			
			l = 0;
			
		}
		void event(HumanEvent e)
		{
			transition(fsm.registered);
			
		}
		void event(NoHumanEvent e)
		{
			l++;
			if(l>=fsm.Llimit)
			{
				transition(fsm.flush);
			}
			
		}
	}registered{ this };
	class Flush : public State
	{
		friend Fsm; using State::State;
		int l;
		void entry()
		{
			printf("%d\n", fsm.timeCnt+1);
			fsm.flushCnt++;
			transition(fsm.notRegister);
		}
		
	}flush { this };
	int flushCnt;
};

int main()
{
	UrinalMachine machine;
	int K, L, N;
	scanf("%d %d %d", &K, &L, &N);
	machine.SetKAndL(K, L);
	for (int i = 0; i < 30'001; i++)
	{
		
		if (i < N)
		{
			char ch;
			scanf(" %1c", &ch);
			machine.SetTimeCnt(i);
			if (ch == '1')
			{
				//printf("Human %d'th\n", i);
				machine.handle(HumanEvent{});
			}
			else
			{
				//printf("NoHuman %d'th\n", i);
				machine.handle(NoHumanEvent{});
			}
		}
		else
		{
			machine.SetTimeCnt(i);
			machine.handle(NoHumanEvent{});
		}
		

		
	}
	if (machine.getFlushCnt() == 0)
	{
		puts("NIKAD");
	}
	//printf("flsuhCnt : %d\n", machine.getFlushCnt());
}