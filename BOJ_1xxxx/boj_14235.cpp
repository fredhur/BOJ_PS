// Title : 크리스마스 선물 https://www.acmicpc.net/problem/14235
#include <iostream>
using namespace std;
using uint = unsigned int;
uint n;
constexpr auto maxHeapSize = (1 << 18);
template <typename T>
class MaxPriorityQueue
{
public:
    MaxPriorityQueue() noexcept
    {
        hn = 0;
    }
    ~MaxPriorityQueue() = default;
    void push(T &data) noexcept
    {
        heap[++hn] = data;
        for (uint c = hn; c > 1 && heap[c] > heap[c / 2];)
        {
            swap(heap[c], heap[c / 2]);
            c = c / 2;
        }
    }
    void pop() noexcept
    {
        swap(heap[1], heap[hn--]);
        uint p = 1, c = 2;
        while (c <= hn)
        {
            if (c < hn && (heap[c + 1] > heap[c]))
                c++;
            if (heap[c] < heap[p])
                break;

            swap(heap[c], heap[p]);
            p = c;
            c = c * 2;
        }
    }
    bool empty() noexcept
    {
        return hn == 0;
    }
    T top() noexcept
    {
        if (empty())
            return T();

        return heap[1];
    }

private:
    
    void swap(T &a, T &b) noexcept
    {
        T t = a;
        a = b, b = t;
    }

    T heap[(maxHeapSize)];
    uint hn;
};

int main()
{
    MaxPriorityQueue<uint> pq;

    cin >> n;
    for (uint i = 0; i < n; i++)
    {
        uint input;
        cin >> input;
        if (input == 0)
        {
            if (pq.empty())
            {
                puts("-1");
            }
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
        {
            for (uint i = 0; i < input; i++)
            {
                uint present;
                cin >> present;
                pq.push(present);
            }
        }
    }
}
