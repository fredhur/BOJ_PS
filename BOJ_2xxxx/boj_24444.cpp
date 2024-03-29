// Title : 알고리즘 수업 - 너비 우선 탐색 1 https://www.acmicpc.net/problem/24444
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
using Vector = vector<vector<int>>;
Vector graph(100007);
queue<int> q;
bool visited[100007];
int ret[100007];
int cnt = 0;
void bfs(Vector &g, int R)
{
    visited[R] = true;
    ret[R] = cnt++;
    q.push(R);

    while (!q.empty())
    {
        auto vertex = q.front();
        q.pop();
        ret[vertex] = cnt++;

        for (auto &i : graph[vertex])
        {
            if (visited[i] == false)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}
int main()
{
    scanf("%d %d %d", &N, &M, &R);
    for (int i = 0; i < M; i++)
    {
        int u, v;
        scanf(" %d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(graph, R);

    for(int i=1; i<=N; i++)
    {
        printf("%d\n", ret[i]);
    }
}