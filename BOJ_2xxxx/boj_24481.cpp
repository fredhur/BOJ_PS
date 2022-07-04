#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
constexpr auto vertextSize = 100005;
vector<vector<int>> v(vertextSize);
int N, M, R;
bool visited[vertextSize];
int visitCnt[vertextSize];
int cnt;
void dfs(int idx, int &depthCnt)
{
    visitCnt[idx] = ++depthCnt;   
    for(auto &i: v[idx])
    {
        if(visited[i] == true) continue;
       
        visited[i] = true;
        dfs(i, depthCnt);
        depthCnt--;
    }
}

int main()
{
    
    scanf("%d %d %d", &N, &M, &R);
    for(int i=1; i<=M; i++)
    {
        int ind, n;
        scanf(" %d %d", &ind, &n);
        v[ind].push_back(n);
        v[n].push_back((ind));
    }
    for(int i=1; i<=N; i++)
    {
       sort(v[i].begin(),v[i].end());
    }
    
    visited[R] = true;
    int cnt = 0;
    dfs(R,cnt);

    for(int i=1; i<=N; i++)
    {
        printf("%d\n", visitCnt[i]-1);
    }
}