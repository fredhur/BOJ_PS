#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
constexpr auto SIZE = 100'000;
vector<vector<int>> v(100'007);
int order[100'007];
struct Node
{
    Node *prev;
    Node *next;
    int data;
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
        if (next)
            next->prev = prev;
        if (prev)
            prev->next = next;
    }
} buf[SIZE];
class Queue
{
public:
    Queue()
    {
        bcnt = 0;
        head.next = &tail;
        tail.prev = &head;
    }
    ~Queue() = default;

    void push(int data)
    {
        buf[bcnt++].alloc(data, tail.prev, &tail);
    }
    bool empty() const
    {
        return head.next == &tail;
    }
    void pop()
    {
        if (empty())
            return;

        head.next->pop();
    }
    int front() const
    {

        return head.next->data;
    }

private:
    int bcnt;
    Node head, tail;
} q;
int N;
struct Lambda
{
    bool operator()(const int &a, const int &b) const
    {
        return order[a] < order[b];
    }
};
vector<int> ret;
vector<int> cmp;
bool visited[100'007];
void bfs(int start)
{
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();

        cmp.push_back(front);

        for (int i = 0; i < v[front].size(); i++)
        {
            if (visited[v[front][i]] == false)
            {

                q.push(v[front][i]);
                visited[v[front][i]] = true;
            }
        }
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        scanf(" %d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int start = 1;

    for (int i = 0; i < N; i++)
    {
        int n;

        scanf(" %d", &n);
        if (i == 0)
            start = n;
        order[n] = i + 1;
        ret.push_back(n);
    }

    if (start != 1)
    {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        sort(v[i].begin(), v[i].end(), Lambda());
    }

    bfs(start);

    puts(ret == cmp ? "1" : "0");
}
