#include <cstdio>
int N;
char arr[104][104];
int SolveRow(char (&arr)[104][104])
{
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == '.')
            {
                cnt++;
            }
            else if (arr[i][j] == 'X')
            {
                if (cnt >= 2)
                {
                    ans++;
                    cnt = 0;
                }
                else
                {
                    cnt = 0;
                }
            }
        }
        if (cnt >= 2)
        {
            ans++;
        }
    }

    return ans;
}
int SolveCol(char (&arr)[104][104])
{
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[j][i] == '.')
            {
                cnt++;
            }
            else if (arr[j][i] == 'X')
            {
                if (cnt >= 2)
                {
                    ans++;
                    cnt = 0;
                }
                else
                {
                    cnt = 0;
                }
            }
        }
        if (cnt >= 2)
        {
            ans++;
        }
    }

    return ans;
}
int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %1c", &arr[i][j]);
        }
    }
    printf("%d %d\n", SolveRow(arr), SolveCol(arr));

    return 0;
}