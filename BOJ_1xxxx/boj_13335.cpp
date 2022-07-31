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
<<<<<<< HEAD
            auto frontTruck = bridge.front();
            if (time - frontTruck.timestamp >= w)
            {
                bridge.pop();
                totWeight -= frontTruck.weight;
=======
            auto frontT = bridge.front();
            if (time - frontT.timestamp >= w)
            {
                bridge.pop();
                totWeight -= frontT.weight;
>>>>>>> 156b8f5eed37c112ff6857d2fe547b84a7b87e0e
            }
        }

        if (!inQ.empty())
        {
<<<<<<< HEAD
            auto Truck = inQ.front();
            if (totWeight + Truck.weight <= l && bridge.size() < w)
            {
                Truck.timestamp = time;
                bridge.push(Truck);
                inQ.pop();
                totWeight += Truck.weight;
=======
            auto T = inQ.front();
            if (totWeight + T.weight <= l && bridge.size() < w)
            {
                T.timestamp = time;
                bridge.push(T);
                inQ.pop();
                totWeight += T.weight;
>>>>>>> 156b8f5eed37c112ff6857d2fe547b84a7b87e0e
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