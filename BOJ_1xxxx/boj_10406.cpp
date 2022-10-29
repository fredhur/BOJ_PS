// Title : The fellowship of the ring https://www.acmicpc.net/problem/10406
#include <cstdio>
int main()
{
    int W,N,P,ans=0;
    scanf("%d%d%d", &W, &N, &P);
    while(P--)
    {
        int H;
        scanf(" %d", &H);
        ans+=(W<=H &&H <=N);
    }
    printf("%d", ans);
}