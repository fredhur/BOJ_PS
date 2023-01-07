#include <cstdio>
template <typename T>
T Min(T a, T b)
{
    return a > b ? b : a;
}

template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    const auto min = Min(a, Min(b, c));
    const auto max = Max(a, Max(b, c));
    printf("%d", a + b + c - min - max);
}