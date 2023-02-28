#include <cstdio>
bool dp[1002];
int main()
{
    
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    dp[4] = 1;
    int N;
    scanf("%d", &N);
    for (int i = 5; i <= N; i++)
    {
        dp[i] = (dp[i - 1] == 0 || dp[i - 3] == 0 || dp[i - 4] == 0);
    }
    puts(dp[N] == true ? "SK" : "CY");
    return 0;
}