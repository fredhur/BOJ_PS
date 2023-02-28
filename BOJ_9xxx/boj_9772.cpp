#include <cstdio>
int main()
{
    double x, y;
    while (true)
    {
        scanf("%lf %lf", &x, &y);
        if (x == 0 && y == 0)
        {
            puts("AXIS");
            break;
        }
        const auto val = x * y;
        if (val == 0)
        {
            puts("AXIS");
        }
        else if (val > 0)
        {
            puts(x > 0 ? "Q1" : "Q3");
        }
        else
        {

            puts(x > 0 ? "Q4" : "Q2");
        }
    }

    return 0;
}