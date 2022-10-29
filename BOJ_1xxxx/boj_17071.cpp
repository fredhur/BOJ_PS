// Title : 숨바꼭질 5 https://www.acmicpc.net/problem/17071
#include <iostream>
#include <queue>
using namespace std;
constexpr auto SIZE = 5'00'000;
int N, K;
int visited[2][SIZE + 1];
int sum(int n)
{
    return (n) * (n + 1) / 2;
}
struct Data
{
    int x;
    int t;
};
queue<Data> q;
void calcSubin()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            visited[i][j] = -1;
        }
    }
    q.push({N, 0});
    visited[0][N] = 0;
    while (!q.empty())
    {
        auto cur = q.front();

        q.pop();

        auto t = (cur.t + 1) % 2;

        if (cur.x * 2 <= SIZE && visited[t][cur.x * 2] == -1)
        {
            visited[t][cur.x * 2] = cur.t + 1;

            q.push({cur.x * 2, cur.t + 1});
        }
        if (cur.x + 1 <= SIZE && visited[t][cur.x + 1] == -1)
        {
            visited[t][cur.x + 1] = cur.t + 1;

            q.push({cur.x + 1, cur.t + 1});
        }
        if (cur.x - 1 >= 0 && visited[t][cur.x - 1] == -1)
        {
            visited[t][cur.x - 1] = cur.t + 1;

            q.push({cur.x - 1, cur.t + 1});
        }
    }
}
void MoveOfSis()
{
    for (int t = 0; t <= SIZE; t++)
    {
        auto sisterPos = sum(t) + K;
        if (sisterPos > SIZE)
            break;

        if((visited[t%2][sisterPos] != -1) && visited[t%2][sisterPos]<=t)
        {
            printf("%d\n", t);
            return;
        }
    }
    puts("-1");
}
int main()
{
    scanf("%d %d", &N, &K);
    if (N == K)
        puts("0");

    else
    {
        calcSubin();
        MoveOfSis();
    }
}