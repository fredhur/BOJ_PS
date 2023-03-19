#include <cstdio>
int main()
{
    constexpr auto INT_MAX = 0x7fffffff;
    int n;
    scanf("%d", &n);
    int maxY = -INT_MAX + 1, maxX = -INT_MAX + 1, minY = INT_MAX, minX = INT_MAX;
    while (n--)
    {
        int x, y;
        scanf(" %d %d", &x, &y);
        minX = minX > x ? x : minX;
        minY = minY > y ? y : minY;
        maxX = maxX < x ? x : maxX;
        maxY = maxY < y ? y : maxY;
    }

    printf("%d", (maxY - minY) * (maxX - minX));
    return 0;
}