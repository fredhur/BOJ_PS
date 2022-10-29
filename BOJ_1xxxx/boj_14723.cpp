// Title : 이산수학 과제 https://www.acmicpc.net/problem/14723
#include <cstdio>
int CalcPrev(int N)
{
    int sum = 0;
    for (int i = 1;; i++)
    {
        sum += i;
        if (sum >= N)
        {
            return i - 1;
        }
    }
    return 0;
}
int main()
{
    int N;
    scanf("%d", &N);

    const int n = CalcPrev(N);
    if (n == N)
    {
        printf("%d %d\n", 1, n);
    }
    else
    {
        const int r = N - (n * (n + 1) / 2);

        printf("%d %d\n", n + 2 - r, r);
    }
    return 0;
}