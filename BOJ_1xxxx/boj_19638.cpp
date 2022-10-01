#include <cstdio>

int T, N, H;

class PriorityQueue
{
public:
    PriorityQueue()
    {
        hn = 0;
    }
    ~PriorityQueue() = default;

    void Push(int data)
    {
        heap[++hn] = data;

        for (int c = hn; c > 1 && heap[c] > heap[c / 2];)
        {
            Swap(heap[c], heap[c / 2]);
            c = c / 2;
        }
    }
    bool Empty()
    {
        return hn == 0;
    }
    int Top()
    {
        return heap[1];
    }
    void Pop()
    {
        Swap(heap[1], heap[hn--]);
        int p = 1, c = 2;

        while (c <= hn)
        {
            if (c < hn && heap[c] < heap[c + 1])
            {
                c++;
            }
            if (heap[c] < heap[p])
                break;

            Swap(heap[c], heap[p]);
            p = c;
            c = c * 2;
        }
    }
    int ChkHeight()
    {
        if (Empty())
            return 0;

        int num = 0;
        for (int i = 1; i <= hn; i++)
        {
            if (heap[i] < H)
            {
                num++;
            }
        }
        return num;
    }

private:
    int hn;
    int heap[100005];
    template <typename T>
    void Swap(T &a, T &b)
    {
        T t = a;
        a = b, b = t;
    }
} pq;

int main()
{
    scanf("%d %d %d", &N, &H, &T);
    for (int i = 0; i < N; i++)
    {
        int giant;
        scanf(" %d", &giant);
        pq.Push(giant);
    }
    int cnt = 0;
    for (cnt = 0; cnt < T; cnt++)
    {
        auto top = pq.Top();
        if (top < H)
            break;

        if (top > 1)
        {
            top /= 2;
        }
        pq.Pop();
        pq.Push(top);
    }
    if (pq.ChkHeight() == N)
    {
        puts("YES");
        printf("%d\n", cnt);
    }
    else
    {
        puts("NO");
        printf("%d\n", pq.Top());
    }
}