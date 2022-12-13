#include <cstdio>
int N, M;
int arr[33][33];
template <typename T>
T MAX(const T &a, const T &b)
{
    return a > b ? a : b;
}
template <typename T>
T MAX(const T &a, const T &b, const T &c)
{
    return MAX(a, MAX(b, c));
}
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %d", &arr[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < M ; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < M; k++)
            {
                int sum = 0;
                for (int ii = 0; ii < N; ii++)
                {
                    sum += MAX(arr[ii][i], arr[ii][j], arr[ii][k]);
                }
                ans = MAX(ans, sum);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}