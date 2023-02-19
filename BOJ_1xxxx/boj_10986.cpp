#include <cstdio>
using ll = long long;
int N, M;

ll pSum[1000007];
ll cnt[1009];
int main()
{
    scanf("%d %d", &N, &M);
   
   
    
    for (int i = 1; i <= N; i++)
    {
        int n;
        scanf(" %d", &n);
        pSum[i] = ((pSum[i - 1] + n) % M);

        

        cnt[pSum[i]]++;
    }
    ll ret = cnt[0];
    for (int i = 0; i < M; i++)
    {
        ret += cnt[i] * (cnt[i] - 1) / 2;
    }

    printf("%lld", ret);

    return 0;
}