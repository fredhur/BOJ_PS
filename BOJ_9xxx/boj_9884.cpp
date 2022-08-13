#include <cstdio>
template <typename T>
inline T MAX(T a, T b)
{
    return a > b ? a : b;
}
template <typename T>
inline T MIN(T a, T b)
{
    return a < b ? a : b;
}
int Gcd(int A, int B)
{
    while (A != B)
    {
        auto max = MAX(A, B);
        auto min = MIN(A, B);
        A = max - min;
        B = min;
    }
    return B;
}

int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    printf("%d\n", Gcd(A, B));
}