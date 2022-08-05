#include <cstdio>

constexpr auto MAX_LIMIT = 0x7fffffff;
int retArr[12], cntArr[12], N;
void Init()
{
     scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &cntArr[i]);
    }
    for (int i = 0; i <= N; i++)
    {
        retArr[i] = MAX_LIMIT;
    }
   
}
int main()
{
    Init();
    for (int i = 1; i <= N; i++)
    {
        for (int j = N; j >= 0; j--)
        {
            auto cnt = 0;
            for (int k = 1; k <= j; k++)
            {
                cnt += (retArr[k] > i);
            }
            if (cnt == cntArr[i])
            {
                retArr[j + 1] = i;
                break;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", retArr[i]);
    }
    return 0;
}