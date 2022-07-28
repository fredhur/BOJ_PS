#include <cstdio>
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}
template <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}

template <typename T>
T Median(T a, T b, T c)
{
    return max(min(a, b), min(max(a, b), c));
}
template <typename T>
T MaxOf3(T a, T b, T c)
{
    return max(max(a, b), c);
}

template <typename T>
T MinOf3(T a, T b, T c)
{
    return min(min(a, b), c);
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int min, med, max;

    min = MinOf3(a, b, c);
    med = Median(a, b, c);
    max = MaxOf3(a, b, c);

    if (min + med > max)
    {
        printf("%d", min + med + max);
    }
    else
    {
        printf("%d", 2 * (min + med) - 1);
    }
}