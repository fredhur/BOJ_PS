// Title : 친구 친구 https://www.acmicpc.net/problem/10865
#include <iostream>
#include <vector>
using namespace std;
int N,M;
vector<vector<int>> v(100'007);
int main()
{
    scanf("%d %d", &N, &M);
    while(M--)
    {
        int a, b;
        scanf(" %d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i=1; i<=N; i++)
    {
        printf("%d\n", v[i].size());
    }
}