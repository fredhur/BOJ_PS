#include <iostream>
using ll = long long;
ll dp[55];

void init()
{
    dp[1] = 1, dp[2] = 1;
    for(int i=3; i<=55; i++)
    {
        dp[i] = dp[i-1] +dp[i-2];
    }
}
int main()
{
    ll n;
    init();
    scanf("%lld", &n);

    const auto s = (n > 2) ? n-2 : 1;
    printf("%lld %lld\n", dp[n], s);

}