// Title : 골드바흐의 추측 https://www.acmicpc.net/problem/6588
#include <cstdio>
#include <cmath>
using ll = int;
constexpr auto NUMS = (1000007);

ll primeNumber[NUMS];

void EratousSieve()
{
    for (int i = 2; i <= NUMS; i++)
    {
        primeNumber[i] = i;
    }

    for (int i = 2; i <= sqrt(NUMS); i++)
    {
        if (primeNumber[i] == 0)
        {
            continue;
        }
        for (int j = i * i; j <= NUMS; j += i)
        {
            primeNumber[j] = 0;
        }
    }
}

void ans(int num)
{
    for (int j = num - 2; j >= 3; j--)
    {
        if (primeNumber[j] && primeNumber[num - j])
        {
            printf("%d = %d + %d\n", num, num - j, j);
            return;
        }
    }
}

int main()
{
    EratousSieve();
    while (true)
    {
        int n;
        scanf("%d", &n);
        if(n==0) break;
        ans(n);

    }

    return 0;
}