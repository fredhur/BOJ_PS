#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<ll> v;
ll reverse(ll n)
{
    ll ret = 0;
    while (n)
    {
        ret = ret * 10 + n % 10;
        n = n / 10;
    }
    return ret;
}
int main()
{
    int N;
    scanf("%d", &N);

    while (N--)
    {
        ll num;
        scanf(" %lld", &num);
        v.push_back(reverse(num));
    }
    sort(v.begin(), v.end());

    for (auto &i : v)
    {
        printf("%lld\n", i);
    }

    return 0;
}