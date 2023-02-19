#include <cstdio>
using Int = unsigned long long;

int lookupTbl[30];
int inputTbl[30];

Int P(Int n, int k)
{
    if (k == 1)
    {
        return n;
    }
    else if (k == 2)
    {
        return n * (n - 1) / 2;
    }
    else
    {
        return n * (n - 1) * (n - 2) / 6;
    }
}
int main()
{

    int N;
    char S[5];

    scanf("%s", S);

    for (int i = 0; S[i]; i++)
    {
        lookupTbl[S[i] - 'A']++;
    }

    scanf(" %d", &N);
    for (int i = 0; i < N; i++)
    {
        char str[15];
        scanf(" %s", str);
        inputTbl[str[0] - 'A']++;
    }
    Int ans = 1;
    for (int i = 0; i < 26; i++)
    {
        if (lookupTbl[i])
        {
            ans *= P(inputTbl[i], lookupTbl[i]);
        }
    }
    printf("%lld\n", ans);

    return 0;
}