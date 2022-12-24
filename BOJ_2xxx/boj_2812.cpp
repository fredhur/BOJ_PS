#include <cstdio>
constexpr auto SIZE = (1 << 19);
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node *alloc(int _data, Node *_prev, Node *_next)
    {
        data = _data;
        prev = _prev;
        next = _next;
        if (prev)
            prev->next = this;
        if (next)
            next->prev = this;

        return this;
    }
    void pop()
    {
        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
        return;
    }
} buf[SIZE];
int bcnt;
class Stack
{
public:
    Stack()
    {
        head.next = &tail;
        tail.prev = &head;
        bcnt = 0;
    }
    ~Stack() = default;
    int Top()
    {
        if (empty())
            return __INT_MAX__;

        else
        {
            return head.next->data;
        }
    }
    bool empty()
    {
        return head.next == &tail && tail.prev == &head;
    }
    void Push(int &data)
    {
        buf[bcnt++].alloc(data, &head, head.next);
    }
    void Pop()
    {
        head.next->pop();
    }
    void Print(const int &PrintCnt)
    {
        Node *p = &tail;
        p = p->prev;
        int cnt = 0;
        while(p != &head && cnt < PrintCnt)
        {
            printf("%d", p->data);
            p = p->prev;
            cnt++;
        }puts("");
    }
private:
    Node head;
    Node tail;
}stk;
int number[500007];
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
    {
        scanf("%1d", &number[i]);
    }
    int count = 0;
    
    for(int i=0; i<N; i++)
    {
        if(stk.empty())
        {
        }
        else 
        {
            while(!stk.empty() && count <K && stk.Top() < number[i])
            {
                count++;
                stk.Pop();
            }
            
        }
        stk.Push(number[i]);
        
    }
   
    stk.Print(N-K);
    return 0;
}