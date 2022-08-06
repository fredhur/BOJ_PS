#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
constexpr auto SIZE = 100007;
ll N, M,R;
using Vector = vector<vector<ll>>;

struct Data 
{
    ll data;
    ll depth;
};
Vector graph(SIZE);
bool visited[SIZE];
ll ret[SIZE];
queue<Data> q;
ll cnt;
void bfs(Vector &g)
{
    visited[R] = true;
    ret[R] = cnt++;
    q.push({R,0});

    while (!q.empty())
    {
        auto vertex = q.front();
        q.pop();
        ret[vertex.data] = (vertex.depth)*(cnt++);

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
int main()
{
    scanf("%lld %lld %lld", &N, &M, &R);
    for(ll i=0; i<M; i++)
    {
        ll u,v;
        scanf(" %lld %lld", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(ll i=1; i<=N; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs(graph);

    for(ll i=1; i<=N; i++)
    {
        ret[0] += ret[i];
    }
    printf("%lld", ret[0]);

}
