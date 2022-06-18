#include <cstdio>

int N, S;
int ans, t;

template <typename T>
T ABS(T a)
{
    return a > 0 ? a : -a;
}
int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    scanf("%d %d", &N, &S);
    scanf(" %d", &t);
    ans = ABS(S - t); // init
    for (int i = 1; i < N; i++)
    {

          scanf(" %d", &t);
        ans = gcd(ans, ABS(S - t));
    }
   printf("%d", ans);
}
