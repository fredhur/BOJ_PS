#include <cstdio>
using ll = long long;
int main()
{
    ll N, K;
    scanf("%lld %lld", &N, &K);
    int cnt = 0;
    for(ll i = K; i<=N ; i = i*K)
    {
        cnt += (N/i);//
    }
    printf("%d\n", cnt);
    // 5! % 3  
    // 5 mod 3 = 2
    // 4 mod 3 = 1
    // 3 mod 3 = 0
    // 2 mod 3 = 2
    // 1 mod 3 = 1
    // 5 > 3, so there exists 0 in here, so divide is always 0
    // we need to find maximum. so just add to cnt


    return 0;
}