// Title : 숫자 https://www.acmicpc.net/problem/10093
#include <cstdio>
using ll = long long;
ll A, B;
template <typename T>
void MaxSwap(T &a, T &b)
{
    if (a > b)
    {
        T t = a;
        a = b, b = t;
    }
}
int main()
{
    scanf("%lld %lld", &A, &B);
    MaxSwap(A, B);
    
    if(A==B)
    {
        puts("0");
        return 0;
    }
    printf("%lld\n", B - A - 1);
    
    for (ll i = A + 1; i < B; i++)
    {
        printf("%lld ", i);
    }
    return 0;
}