#include <cstdio>
int X, Y, d, i;
int main()
{
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &d);
        X = (X | (d << (4 - i)));
    }
    for (i = 0; i < 5; i++)
    {
        scanf(" %d", &d);
        Y = (Y | (d << (4 - i)));
    }
    puts((X ^ Y) == 31 ? "Y" : "N");
}