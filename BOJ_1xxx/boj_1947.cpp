#include <cstdio>
constexpr auto mod = 1'000'000'000;
using ll = long long;
ll dp[1000007];
int main()
{
    int N;
    scanf("%d", &N);
    dp[1] = 0, dp[2] = 1;
    for(auto i=3; i<=N; i++)
    {
        dp[i] = ((i-1)%mod)*((dp[i-1]%mod+dp[i-2]%mod)%mod)%mod;
        // An = (n-1) x (An-1 + An-2)
    }
    
    printf("%lld\n", dp[N]);
    return 0;
}