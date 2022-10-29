// Title : St. Ives https://www.acmicpc.net/problem/4696
#include <cstdio>
int main()
{
    while(true)
    {
        double N;
        scanf("%lf", &N);
        if(N==0) break;
        double ans = 0;
        for(int i=0; i<5; i++)
        {
            ans = ans*N + 1;
        }
        printf("%.2lf\n", ans);
    }
}