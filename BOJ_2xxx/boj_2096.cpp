// boj 2096 bomb solution.
#include <cstdio>
using ll = long long;
ll ans;
constexpr auto mod = 10301;
int A, B, N;
ll dp[1003][1003];
void init()
{
    for (auto i = 0; i < 1003; i++)
    {
        dp[i][i] = 1;
    }
}
int main()
{
    scanf("%d%d%d", &N, &A, &B);
    init();
    // count from 1 to N.
    for (int i = 2; i <= N; i++)
    {
        for (int j = i / 2; j >= 1; j--)
        {
            dp[i][j] = (dp[i][j] + dp[i - j][j]) % mod;
            if (i >= j * 2 + 2)
            {
                dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
            }
        }
    }

    for (auto i = A; i <= N - B; i++)
    {
        for (auto j = B; j <= N - i; j++)
        {
            ans = (dp[i][A] * dp[j][B] + ans) % mod;
        }
    }
    printf("%lld", ans);
    return 0;
}