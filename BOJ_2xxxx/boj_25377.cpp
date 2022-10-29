// Title : 빵 https://www.acmicpc.net/problem/25377
#include <cstdio>
int N;
#define INT_MAX (0x7fffffff)
template <typename T>
inline T min(T a, T b)
{
    return a < b ? a : b;
}
int main()
{
    scanf("%d", &N);
    int ans = INT_MAX;
    while(N--)
    {
        int A, B;
        scanf(" %d %d", &A, &B);
        if(A<=B)
        {
            ans = min(ans, B);
        }
    }   
    printf("%d", ans == INT_MAX ? -1 : ans);
    return 0;
}