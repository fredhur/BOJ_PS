// Title : 最頻値 (Mode) https://www.acmicpc.net/problem/18413
#include <cstdio>
int N,M;
int saveN[105];
int main()
{
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
    {
        int n;
        scanf(" %d", &n);
        saveN[n]++;
        
    }

    int max = -1;
    for(int i=1; i<=M; i++)
    {
        max = (max < saveN[i]) ? saveN[i] : max;
    }
    printf("%d\n", max);
}