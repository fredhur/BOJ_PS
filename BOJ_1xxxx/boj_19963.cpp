#include <cstdio>
int n, m, k;
bool arr[105];
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    const int cnt = n - m - k;
    while (m--)
    {
        int n;
        scanf(" %d", &n);
        arr[n] = true;
    }
    while (k--)
    {
        int n;
        scanf(" %d", &n);
        arr[n] = true;
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == false)
        {
            printf("%d ", i);
        }
    }
    puts("");
    return 0;
}