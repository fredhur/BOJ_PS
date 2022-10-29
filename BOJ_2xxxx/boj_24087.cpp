// Title : アイスクリーム (Ice Cream) https://www.acmicpc.net/problem/24087
#include <cstdio>
int S, A, B;
int main()
{
    scanf("%d %d %d", &S, &A, &B);
    const auto diff = S - A;
    if (diff <= 0)
    {
        puts("250");
    }
    else
    {
        const int tot = (diff % B == 0) ? diff / B : diff / B + 1;
        printf("%d\n", 250 + 100 * tot);
    }
}