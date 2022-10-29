// Title : 미국 스타일 https://www.acmicpc.net/problem/2712
#include <cstdio>
int tc;
char *s[] = {"lb", "l", "g", "kg"};
const int M(const char *s)
{
    const auto kg = 'k' + 'g';
    const auto g = 'g';
    const auto l = 'l';
    const auto lb = 'l' + 'b';
    int a = s[1] == 0 ? s[0] : s[0] + s[1];
    switch (a)
    {
    case kg:
        return 0;
    case g:
        return 1;
    case l:
        return 2;
    case lb:
        return 3;
    default:
        return 4;
    }
}
double C(char *s)
{
    static double c[4] = {2.2046, 3.7854, 0.2642, 0.4536};
    return c[M(s)];
}
int main()
{
    scanf("%d", &tc);
    while (tc--)
    {
        double t;
        char u[2];
        scanf(" %lf %s", &t, u);
        printf("%.4lf %s\n", t * C(u), s[M(u)]);
    }
    return 0;
}