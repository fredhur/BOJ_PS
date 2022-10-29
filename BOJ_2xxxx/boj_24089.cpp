// Title : ボールの移動 (Moving Balls) https://www.acmicpc.net/problem/24089
#include <cstdio>
int N, M;
int ballIdx[2005];
void init()
{
    for(int i=1; i<=N; i++)
    {
        ballIdx[i] = i;
    }
}
int main()
{
    scanf("%d %d", &N, &M);  
    init();
    for(int i=0; i<M; i++)
    {
        int X,Y;
        scanf(" %d %d", &X, &Y);
        ballIdx[X] = Y;
    }
    for(int i=1; i<=N; i++)
    {
        printf("%d\n", ballIdx[i]);
    }
    return 0;
}
