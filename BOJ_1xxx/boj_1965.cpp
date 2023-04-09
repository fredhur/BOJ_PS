#include <cstdio>
int N , max;
int dp[1006];
int arr[1005];
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &arr[i]);
    

    for(int i=0; i<N; i++)
    {
        dp[i] =1;
        for(int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])
            {
                if(dp[i] < dp[j]+1) dp[i] = dp[j]+1;
            }
        }
        max = max > dp[i] ? max : dp[i];
    }
    printf("%d", max);

    return 0;
}