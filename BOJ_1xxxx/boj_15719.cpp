// Title : 중복된 숫자 https://www.acmicpc.net/problem/15719
#include <cstdio>
using ll = long long;
int main()
{
    ll N;
    scanf("%lld", &N);
    ll sum = 0;
    for (int i = 0; i < N; i++)
    {
        ll n;
        scanf(" %lld", &n);
        sum += n;
    }
    printf("%lld\n", sum - ((N) * (N - 1) / 2 ));
    return 0;
}