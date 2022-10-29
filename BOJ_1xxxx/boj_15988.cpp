// Title : 1, 2, 3 더하기 3 https://www.acmicpc.net/problem/15988
#include <cstdio>
using ll = long;
static constexpr auto SIZE = 1'000'007;
static constexpr auto mod = 1'000'000'009;

static ll arr[SIZE];
constexpr static void init()
{
    
    arr[1] = 1, arr[2] = 2, arr[3] = 4, arr[4] = 7;

    for (auto i = 4; i < SIZE; i++)
    {
        arr[i] = (arr[i - 1] % mod + arr[i - 2] % mod + arr[i - 3] % mod) % mod;
    }
}
int main()
{
    init();
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        int n;
        scanf(" %d", &n);
        printf("%lld\n", arr[n]);
    }
    return 0;
}