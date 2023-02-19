#include <cstdio>

auto gcd(int x, int y) -> int
{
    while (x != y)
    {

        if (x > y)
        {
            x = x - y;
        }
        else
        {
            y = y - x;
        }
    }
    return x;
}
int dp[1003];
void Init()
{
  dp[1] = 3;
  for(int i=2; i<=1001; i++)
  {
    int cnt =0;
    for(int j=1; j<=i; j++)
    {// 서로소의 갯수를 세서 N 까지 갯수를 계속 저장.
        if(gcd(i,j)==1) 
        {
            cnt +=2 ;// i,j 서로소이면 j,i도 vise versa
        }
        
    }
    dp[i] = dp[i-1]+cnt;
  }
}
int main()
{
    Init();
    int C;
    scanf("%d", &C);
    while (C--)
    {
        int N;
        scanf("%d", &N);
        
        printf("%d\n", dp[N]);
    }
}