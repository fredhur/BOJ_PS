// Title : CD https://www.acmicpc.net/problem/4158
#include <cstdio>
#include <algorithm>
using namespace std;
using uint = unsigned int;
uint cd[1000007];
int main()
{
    while(true)
    {
        uint N, M;
        scanf("%u %u", &N, &M);
        if(N==0 && M==0) break;
        uint ans = 0;
        for(int i=0; i<N; i++)
        {
            scanf(" %u", &cd[i]);
        }
        while(M--)
        {
            uint tar;
            scanf(" %u", &tar);
            ans += binary_search(cd, cd+N, tar);
        }
        printf("%u\n", ans);
    }
    return 0;
}