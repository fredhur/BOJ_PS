#include <cstdio>
int main()
{
    while (true)
    {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;

        printf("%d\n", n * (n + 1) / 2);
    }
    return 0;
}