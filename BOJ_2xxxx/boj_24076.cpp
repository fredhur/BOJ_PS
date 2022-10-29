// Title : IOI 文字列 (IOI String) https://www.acmicpc.net/problem/24076
#include <cstdio>
class State 
{
public:
    State()
    {
        state = 's';
        changeCnt = 0;
    }
    ~State() = default;
    int GetCnt() const 
    {
        return changeCnt;
    }
    void Calc(char ch)
    {
        if(state == 's') // start state
        {
            if(ch == 'I')
            {
                state = 'I';
                return;
            }
            else 
            {
                state= 'I';
                changeCnt++;
                return;
            }
        }
        else if(state == 'I')
        {
            if(ch == 'O')
            {
                state = 'O';
                return;
            }
            else 
            {
                state = 'O';
                changeCnt++;
                return;
            }
        }
        else if(state == 'O')
        {
            if(ch=='I')
            {
                state = 'I';
                return;
            }
            else 
            {
                state = 'I';
                changeCnt++;
                return;
            }
        }
    }
private:

    char state;
    int changeCnt ;
}state;
int main()
{
    
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        char ch;
        scanf(" %1c", &ch);
        state.Calc(ch);
    }
    printf("%d\n", state.GetCnt());
    return 0;
}