// Title : 알고리즘 수업 - 깊이 우선 탐색 2 https://www.acmicpc.net/problem/24480
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v(100005);
int N, M, R;
bool visited[100005];
int visitCnt[100005];
int cnt;
void dfs(int idx)
{
    visitCnt[idx] = ++cnt;   
    for(auto &i: v[idx])
    {
        if(visited[i] == true) continue;
       
        visited[i] = true;
        dfs(i);
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
       sort(v[i].begin(),v[i].end(), greater<int>());
    }
    visited[R] = true;
    dfs(R);

    for(int i=1; i<=N; i++)
    {
        printf("%d\n", visitCnt[i]);
    }
}

