// Title : The Fastest Sorting Algorithm In The World https://www.acmicpc.net/problem/23235
#include <cstdio>
int main()
{
    int N;
    int cnt =0;
    while(true)
    {
        scanf("%d", &N);
        if(N==0) break;

        for(int i=0; i<N; i++)
        {
            int discard;
            scanf(" %d", &discard);
        }
        printf("Case %d: Sorting... done!\n", ++cnt);
    }   
    return 0;
}