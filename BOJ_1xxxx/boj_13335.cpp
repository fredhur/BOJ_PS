#include <iostream>
#include <queue>
using namespace std;
struct Truck
{
    int timestamp;
    int weight;
};
int n, w, l;
int totWeight;
queue<Truck> inQ;
queue<Truck> bridge;
int Solve()
{
    int time = 0;
    for (time = 0; !inQ.empty() || !bridge.empty(); time++)
    {
        if (!bridge.empty())
        {
            auto frontT = bridge.front();
            if (time - frontT.timestamp >= w)
            {
                bridge.pop();
                totWeight -= frontT.weight;
            }
        }

        if (!inQ.empty())
        {
            auto T = inQ.front();
            if (totWeight + T.weight <= l && bridge.size() < w)
            {
                T.timestamp = time;
                bridge.push(T);
                inQ.pop();
                totWeight += T.weight;
            }
        }
    }
    return time;
}
int main()
{
    scanf("%d %d %d", &n, &w, &l);
    for (int i = 0; i < n; i++)
    {
        Truck n;
        scanf(" %d", &n.weight);
        inQ.push(n);
    }
    printf("%d\n", Solve());
}