// Title : XOR https://www.acmicpc.net/problem/10464
#include <iostream>
using ll = long long;
ll xorAtoB(ll n)
{
    const ll lut[]=
    {
        n,
        1,
        n+1,
        0
    };
    const auto m = n&(4-1);
    return lut[m];
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        ll s, f;
        scanf(" %lld %lld", &s, &f);
        printf("%lld\n", xorAtoB(s-1)^xorAtoB(f));
    }
    return 0;
}