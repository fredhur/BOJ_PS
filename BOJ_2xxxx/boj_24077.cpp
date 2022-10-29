// Title : 比較 (Comparison) https://www.acmicpc.net/problem/24077
#include <cstdio>
int A[103];
int B[103];
int ans;
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++)
    {
        scanf(" %d", &A[i]);
    }
    for(int j=0; j<M; j++)
    {
        scanf(" %d", &B[j]);
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            if(A[i] <= B[j])
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}