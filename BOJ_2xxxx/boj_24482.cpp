#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, R;
constexpr auto SIZE = 1'000'007;
using Vector = vector<vector<int>>;
Vector graph(SIZE);
bool visited[SIZE];
int ret[SIZE];
void dfs(int v,int depth)
{
    visited[v] = true;
    ret[v] = depth;
    for(auto &i : graph[v])
    {
        if(visited[i] == false)
        {
            dfs(i, depth+1);
        }
    }

}

int main()
{
    scanf("%d %d %d", &N, &M, &R);
    for(int i=0; i<M; i++)
    {
        int u,v;
        scanf(" %d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1; i<=N; i++)
    {
        auto lambda = [](const int &a, const int &b)
        {
            return a>b;
        };
        sort(graph[i].begin(), graph[i].end(),lambda);
    }
    dfs(R,0);

    for(int i=1; i<=N; i++)
    {
        if(visited[i] == false)
        {
            puts("-1");
        }
        else 
        {
           printf("%d\n", ret[i]);
        }
    }
}