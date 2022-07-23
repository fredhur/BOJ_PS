#include <stdio.h>
int dp[1005];
int P[10007];
int main(void)
{
    int N,i,j;
   
    int min;
    scanf("%d", &N);
    for(i=1; i<=N; i++)
    {
        scanf(" %d", &P[i]);
    }
    dp[1] = P[1];
    for(i=2; i<=N; i++)
    {
        min = P[i];
        for(j=1; j < i; j++)
        {
            if(min > dp[j] + dp[i-j])
            {
                 min = dp[j] + dp[i-j];
            }
               
        }
        dp[i] = min;
    }
    printf("%d\n", dp[N]);
   
    return 0;
}