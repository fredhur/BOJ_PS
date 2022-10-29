// Title : 오큰수 https://www.acmicpc.net/problem/17298
#include <cstdio>
constexpr auto SIZE = 1'000'007;
struct Node
{
    Node *prev;
    Node *next;
    int data;
    Node *alloc(int _data, Node *_prev, Node *_next)
    {
        data = _data;
        prev = _prev, next = _next;
        if(prev)prev->next = this;

        if(next)next->prev = this;
        
        return this;
    }
    void pop()
    {
        if(prev) prev->next = next;
        
        if(next) next->prev = prev;   
    }
}buf[SIZE];
class Stack
{
public:
    Stack() 
    {
        bcnt = 0;
        head.next= nullptr;
    }
    ~Stack() = default;
    void Push(int data)
    {
        buf[bcnt++].alloc(data, &head, head.next);
    }
    void Pop()
    {
        if(Empty()) return;

        head.next->pop();
    }
    int Head()
    {
        return head.next->data;
    }
    bool Empty()
    {
        return head.next == nullptr;
    }
private:
    int bcnt;
    Node head;
}stk;
int N;
int arr[SIZE];
int ret[SIZE];
int main()
{
    
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        scanf(" %d", &arr[i]);
    }
    for(int i=N-1; i>=0 ; i--)
    {
        while (!stk.Empty() && stk.Head() <= arr[i])
        {
            stk.Pop();
        }

        if(stk.Empty())
        {
            stk.Push(arr[i]);
            ret[i] = -1;
        }
        else
        {
            const auto Head = stk.Head();
            ret[i] = Head == arr[i] ? -1 : Head;
            stk.Push(arr[i]);
        }
    }

    for(int i=0; i<N; i++)
    {
        printf("%d ", ret[i]);
    }
}
