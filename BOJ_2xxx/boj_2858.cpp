// Title : 기숙사 바닥 https://www.acmicpc.net/problem/2858
#include <cstdio>
int R, B;
int main()
{
    scanf("%d %d", &R, &B);
    const auto tot = R + B;
    for (int i = tot; i >= 1; i--)
    {
        const auto t = tot / i;
        if (tot % i == 0 && ((t + t + i + i - 4) == R))
        {
            printf("%d %d", i, t);
            return 0;
        }
    }
    return 0;
}
