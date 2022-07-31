#include <cstdio>
using uint = unsigned long long;
uint N, M,ret,num;
int main()
{
    scanf("%llu %llu", &N, &M);
    scanf(" %llu", &num);
    ret = num % M;
    for (uint i = 1; i < N; i++)
    {
        scanf(" %llu", &num);

        ret = ((ret % M) * (num % M)) % M;
    }
    printf("%llu", ret);
    return 0;
}