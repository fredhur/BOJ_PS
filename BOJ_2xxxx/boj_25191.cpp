// Title : 치킨댄스를 추는 곰곰이를 본 임스 https://www.acmicpc.net/problem/25191
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