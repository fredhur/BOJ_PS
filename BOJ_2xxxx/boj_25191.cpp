#include <cstdio>
int N,A,B;
int main()
{
    scanf("%d", &N);
    scanf(" %d %d", &A, &B);
    const int max = (A/2)+B;
    printf("%d", N < max ? N : max);
    return 0;
}