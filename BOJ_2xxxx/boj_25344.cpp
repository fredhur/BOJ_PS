#include <cstdio>
using ll = long long;
static ll gcd(ll a, ll b)
{
    ll r, i;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ll arr[100007];
int main()
{
    ll N;
    scanf("%lld", &N);
    for (ll i = 0; i < N - 2; i++)
    {
        scanf(" %lld", &arr[i]);
    }
    ll ans = arr[0];
    for (ll i = 1; i < N - 2; i++)
    {
        auto GCD = gcd(ans, arr[i]);
        auto LCM = ans * arr[i]/GCD;
        ans = LCM;
    }
    printf("%lld", ans);
    return 0;
}