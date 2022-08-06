#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, R;
struct Data 
{
    int data;
    int depth;
};
using Vector = vector<vector<int>>;
Vector graph(100007);
queue<Data> q;
bool visited[100007];
int ret[100007];
int cnt ;
void bfs(Vector &g, int R)
{
    visited[R] = true;
    ret[R] = cnt;
    q.push({R,0});

    while (!q.empty())
    {
        auto vertex = q.front();
        q.pop();
        ret[vertex.data] = vertex.depth+1;

        for (auto &i : graph[vertex.data])
        {
            if (visited[i] == false)
            {
                q.push({i, vertex.depth+1});
                visited[i] = true;
            }
        }
    }
}
struct Func
{
    bool operator()(const int &a, const int &b) const
    {
        return a > b;
    }
};
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
        sort(graph[i].begin(), graph[i].end(), Func());
    }

    bfs(graph, R);

    for(int i=1; i<=N; i++)
    {
        printf("%d\n", ret[i]-1);
    }
}