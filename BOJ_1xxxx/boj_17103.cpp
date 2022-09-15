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
    int ans = 0;
    for (int j = num - 2; j >= num/2; j--)
    {
        if (primeNumber[j] && primeNumber[num - j])
        {
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    EratousSieve();
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        scanf(" %d", &n);
        ans(n);
    }
   

    return 0;
}