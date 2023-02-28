#include <cstdio>

using ll = long long;
bool dp[1002];
template <typename T>
T Square(T a, T exponent)
{

    if (exponent == 0)
        return 1;
    else if (exponent == 1)
        return a;

    if (exponent % 2 == 0)
    {
        return Square(a, exponent / 2) * Square(a, exponent / 2);
    }
    else
    {
        return a * Square(a, (exponent - 1) / 2) * Square(a, (exponent - 1) / 2);
    }
}

ll N;

bool func(int a, int square4x)
{

    return dp[a - square4x] == 1;
}
int main()
{
    // dp[0] = 0;

    // scanf("%lld", &N);

    // for(int i=1; i<=N; i++)
    // {
    //     int cnt = 0;
    //     while( i- Square(4, cnt) >=0 )
    //     {
    //         if(!dp[i-Square(4,cnt)])
    //         {
    //             dp[i] = 1;
    //             break;
    //         }
    //         cnt++;
    //     }
    // }

    // for(int i=1; i<=30; i++)
    // {
    //     printf("(%d) : win? (%d)\n", i, dp[i]);
    // }

    scanf("%lld", &N);

    if (N % 5 == 0 || N % 5 == 2)
    {
        puts("CY");
    }
    else
    {
        puts("SK");
    }
    return 0;
}