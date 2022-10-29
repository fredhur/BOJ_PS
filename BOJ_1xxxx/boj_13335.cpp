// Title : 트럭 https://www.acmicpc.net/problem/13335
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
            auto frontTruck = bridge.front();
            if (time - frontTruck.timestamp >= w)
            {
                bridge.pop();
                totWeight -= frontTruck.weight;
            }
        }

        if (!inQ.empty())
        {
            auto Truck = inQ.front();
            if (totWeight + Truck.weight <= l && bridge.size() < w)
            {
                Truck.timestamp = time;
                bridge.push(Truck);
                inQ.pop();
                totWeight += Truck.weight;
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