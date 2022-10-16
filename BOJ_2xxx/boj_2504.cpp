#include <cstdio>
struct Node
{
    char ch;
    Node *prev;
    Node *next;
    Node *alloc(char _ch, Node *_prev, Node *_next)
    {
        prev = _prev;
        next = _next;
        ch = _ch;
        if (prev) prev->next = this;

        if (next) next->prev = this;

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
} buf[40];

class Stack
{
public:
    Stack()
    {
        scnt = 0;
        head.next = nullptr;
        head.prev = nullptr;
    }
    ~Stack() = default;
    char top()
    {
        if (empty())
            return NULL;

        return head.next->ch;
    }
    void push(char ch)
    {
        buf[scnt++].alloc(ch, &head, head.next);
    }
    bool empty()
    {
        return head.next == nullptr;
    }
    void pop()
    {
        if(empty())
        {
            return;
        }
        head.next->pop();
    }
    void PrintStatus()
    {
        Node *p = &head;
        p = p->next;
        for(;p;p=p->next)
        {
            printf("[%c] ", p->ch);
        }puts("");
    }
private:
    int scnt;
    Node head;
} stk;

char str[33];
int main()
{
    scanf("%s", str);
    int sum = 0;
    int tempSum = 1;
    for (int i = 0; str[i]; i++)
    {
        char ch = str[i];
       
        if (ch == '[')
        {
            tempSum *= 3;
            stk.push(ch);

          
        }
         else if(ch == '(')
        {
            tempSum *=2;
            stk.push(ch);
          
        }
        else if(ch == ']')
        {
            const char ctop = stk.top();
            if (stk.empty() || ctop == '(')
            {
                sum = 0;
                break;
            }
            if (str[i-1] == '[')
            {
                sum += tempSum;
            }
            tempSum = tempSum / 3;
            stk.pop();
            
        }
       
        else 
        {
             const char ctop = stk.top();
            
            
            if(stk.empty() || ctop == '[')
            {
                sum = 0;
                break;
            }
            
            
            if (str[i-1] == '(' )
            {
               sum+= tempSum;
            }
            tempSum= tempSum/2;
            stk.pop();
        }
       
    }
    if(!stk.empty())
    {
        puts("0");
    }
    else printf("%d\n", sum);
    return 0;
}