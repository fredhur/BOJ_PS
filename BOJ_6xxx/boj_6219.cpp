// Title : 소수의 자격 https://www.acmicpc.net/problem/6219
#include <cstdio>
#include <cmath>
using ll = int;
constexpr auto NUMS = (4000007);

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
int chk(int N, int D)
{
    while (N > 0)
    {
        int t = N % 10;
        N = N / 10;
        if (t == D)
            return true;
    }
    return false;
}
int ans(int A, int B, int D)
{
    int cnt = 0;
    for (int i = A; i <= B; i++)
    {
        if(primeNumber[i])
        {
             cnt += chk(i, D);
        }
       
    }
    return cnt;
}

int main()
{
    int A, B, D;
    EratousSieve();
    scanf("%d %d %d", &A, &B, &D);

    printf("%d\n", ans(A, B, D));

    return 0;
}