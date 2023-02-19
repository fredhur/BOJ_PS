#include <cstdio>
#define MOD 1'000'000'007
int main()
{
    int N, M;
    int dp[10005];
    scanf("%d %d", &N, &M);
    
    for(int i=1; i<=M; i++) dp[i] = 1;

    dp[M] = 2;

    for (int i = M + 1; i <= N; i++)
          dp[i] = ((dp[i - 1] % MOD) + ((i - M >= 1 ? dp[i - M] : 0) % MOD)) % MOD;
    

    printf("%d", dp[N]);

    return 0;
}