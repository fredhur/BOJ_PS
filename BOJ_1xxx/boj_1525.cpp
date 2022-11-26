// Title : 퍼즐 https://www.acmicpc.net/problem/1525
#include <cstdio>
#include <queue>
using namespace std;
using UI = unsigned int;
struct Data
{
    int cnt;
    int data[9];
    void add (int _data[9])
    {
        for(int i=0; i<9; i++)
        {
            data[i] = _data[i];
        }
    }
};
#define SIZE (1 << 17)
UI hashf(int str[9])
{
    int i = 0;
    UI hash = 5381;
    for (i = 0; i < 9; i++)
    {
        hash = hash * 33 + str[i];
    }
    return hash % SIZE;
}
struct Node
{
    Node *next;
    Node *prev;
    int data[9];
    int id;
    int age;
    Node *alloc(int _data[9], Node *_prev, Node *_next)
    {
        for (int i = 0; i < 9; i++)
        {
            data[i] = _data[i];
        }
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
} buf[200000];
int bcnt;
Node htab[SIZE];
bool compare(int *a, int *b)
{
    for (int i = 0; i < 9; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
struct Hash
{

    void push(int *data)
    {
        int key = hashf(data);
        Node *p = probing(data);
        if (p)
        {
           
        }
        else
        {
            buf[bcnt++].alloc(data, &htab[key], htab[key].next);
        }
    }
    Node *probing(int *data)
    {
        int key = hashf(data);
        Node *p = &htab[key];
        p = p->next;
        for (; p; p = p->next)
        {
            if (compare(p->data, data) == true)
            {
                return p;
            }
        }
        return 0;
    }
}hashTbl;

void init()
{
    bcnt = 0;
    for (int i = 0; i < SIZE; i++)
    {
        htab[i].next = 0;
    }
}
bool cmp(int arr[9])
{
    static int match[9] = {1,2,3,4,5,6,7,8,0};

    for(int i=0; i<9; i++)
    {
       
        if(match[i] != arr[i])
        {
            return false;
        }
    }
    return true;
}
queue<Data> q;
int bfs(int arr[9])
{
    Data d;
    d.add(arr);
    d.cnt = 0;
    hashTbl.push(arr);

    q.push(d);

    while(!q.empty())
    {
        auto first = q.front();
        q.pop();
        auto topData = first.data;

        if(cmp(topData))
        {
            return first.cnt;
        }
        int zeroindex;
        for(int i=0; i<9; i++)
        {
            if(topData[i] == 0)
            {
                zeroindex  = i;
                break;
            }
        }
        int zY = zeroindex/3;
        int zX = zeroindex%3;
        int temp[9];
        for(int d=0; d<4; d++)
        {
            for(int j=0; j<9; j++)
            {
                temp[j] = topData[j];
            }
            if(d==0)
            {
                if(zY !=0)
                {
                    int nY = zY -1;
                    int nX = zX;
                    int n = nY*3 +nX;
                    std::swap(temp[zeroindex], temp[n]);
                    
                    if(hashTbl.probing(temp))
                    {

                    }
                    else 
                    {
                        hashTbl.push(temp);
                        Data d;
                        d.add(temp);
                        d.cnt = first.cnt+1;
                        q.push(d);
                    }
                }
            }
            else if(d==1)
            {
                if(zY !=2)
                {
                    int nY = zY +1;
                    int nX = zX;
                    int n = nY*3 +nX;
                    std::swap(temp[zeroindex], temp[n]);
                    
                    if(hashTbl.probing(temp))
                    {

                    }
                    else 
                    {
                        hashTbl.push(temp);
                        Data d;
                        d.add(temp);
                        d.cnt = first.cnt+1;
                        q.push(d);
                    }
                }
            }
            else if(d==2)
            {
                if(zX !=0)
                {
                    int nY = zY;
                    int nX = zX -1;
                    int n = nY*3 +nX;
                    std::swap(temp[zeroindex], temp[n]);
                    
                    if(hashTbl.probing(temp))
                    {

                    }
                    else 
                    {
                        hashTbl.push(temp);
                        Data d;
                        d.add(temp);
                        d.cnt = first.cnt+1;
                        q.push(d);
                    }
                }
            }
            else 
            {
                if(zX !=2)
                {
                    int nY = zY;
                    int nX = zX +1;
                    int n = nY*3 +nX;
                    std::swap(temp[zeroindex], temp[n]);
                    
                    if(hashTbl.probing(temp))
                    {

                    }
                    else 
                    {
                        hashTbl.push(temp);
                        Data d;
                        d.add(temp);
                        d.cnt = first.cnt+1;
                        q.push(d);
                    }
                }
            }
        }
    }
    return -1;
    
}
int main()
{
    init();
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int n = 0;
    int start[9];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            start[n++] = arr[i][j];
        }
    }

    printf("%d\n",bfs(start));
}