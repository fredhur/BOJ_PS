#include <cstdio>
int main()
{
    long long R, C, N;
    scanf("%d %d %d", &R, &C, &N);

    printf("%lld", (R / N + (R % N > 0)) * (C / N + (C % N > 0)));
    return 0;
}