#include <cstdio>


struct Node
{
    int data;
    Node *prev;
    Node *next;
    void alloc(int &data_, Node *prev_, Node *next_)
    {
        data = data_;
        prev = prev_;
        next = next_;
        if (prev)
            prev_->next = this;
        if (next)
            next_->prev = this;
    }
    void pop()
    {
        if (prev)
            prev->next = next;
        if (next)
            next->prev = prev;
    }
}buf[1<<20];




class Dequeue
{
public:
    Dequeue()
    {
        bcnt = 0;
        head.next = &tail;
        tail.prev = &head;
    }

    void pushFront(int data)
    {
        buf[bcnt++].alloc(data, &head, head.next);
    }
    int GetFront()
    {
        return head.next->data;
    }
    void popFront()
    {
        if (!empty())
            head.next->pop();
    }
    void pushRear(int data)
    {
        buf[bcnt++].alloc(data, tail.prev, &tail);
    }
    int GetRear()
    {
        return tail.prev->data;
    }

    void popRear()
    {
        if (!empty())
        {
            tail.prev->pop();
        }
    }
    void Print()
    {
        Node *p = &head;
        p = p->next;

        for (; p != &tail; p = p->next)
        {
            printf("%d ", p->data);
        }
    }

private:
    bool empty()
    {
        return head.next == &tail;
    }
    
    Node head, tail;
    int bcnt;
};
int N;
int main()
{
    scanf("%d", &N);
    Dequeue dq;

    for (int i = N; i >= 1; i--)
    {
        dq.pushFront(i);
        for (int j = 0; j < i; j++)
        {
            int dat = dq.GetRear();
            dq.popRear();
            dq.pushFront(dat);
        }
    }
    dq.Print();
}