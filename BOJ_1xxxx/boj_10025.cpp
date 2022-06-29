#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int N,K;
int ice[1'000'007];
int g, x;
ll psum[1'000'007],ans;
ll CalcSum(int start, int end)
{
    return psum[end] - psum[start] + ice[start];
}
int main()
{
    scanf("%d %d", &N, &K);
    int maxXpos = 0;
    int minXpos = 0x7fffffff;
    for (int i = 0; i < N; i++)
    {
       
        scanf("%d %d", &g, &x);
        ice[x] = g;
        maxXpos = std::max(maxXpos, x);
        minXpos = std::min(minXpos, x);
    }
    psum[0] = ice[0];
    for(auto i=1; i<=maxXpos; i++)
    {
        psum[i] = psum[i-1] + ice[i];
    }

    for(auto i=minXpos; i<= maxXpos; i++)
    {
        int s = std::max(minXpos, i-K);
        int e = std::min(maxXpos, i+K);

        ans = std::max(ans, CalcSum(s,e));
    }
    printf("%d", ans);

    return 0;
}