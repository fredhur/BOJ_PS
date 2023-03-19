#include <cstdio>
using ll = long long;
ll map[1002][1002];
ll tmp[1003];
template <typename T>
T ABS(T N)
{
    return N > 0 ? N : -N;
}
void Merge(ll arr[], int s, int m, int e)
{
    int i = s;
    int j = m + 1;
    int k = s;
    while (i <= m && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    if (i <= m)
    {
        for (int t = i; t <= m; t++)
        {
            tmp[k++] = arr[t];
        }
    }
    else
    {
        for (int t = j; t <= e; t++)
        {
            tmp[k++] = arr[t];
        }
    }

    for (int i = s; i <= e; i++)
    {
        arr[i] = tmp[i];
    }
}

void MergeSort(ll *arr, int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        MergeSort(arr, s, m);
        MergeSort(arr, m + 1, e);
        Merge(arr, s, m, e);
    }
}

int main()
{

    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ll num;
            scanf(" %lld", &num);
            map[j][i] = num;
        }
    }

    for (int i = 0; i < N; i++)
    {
        MergeSort(map[i], 0, M - 1);
    }

    if (M % 2 == 0) // even
    {
        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            ll median =((map[i][M >>1] + map[i][(M - 1) >>1]) >>1);
            for (int j = 0; j < M; j++)
            {
                ans += (ABS(map[i][j] - median));
            }
        }
        printf("%lld\n", ans);

        for (int i = 0; i < N; i++)
        {
            ll median =((map[i][M >>1] + map[i][(M - 1) >>1]) >>1);
            printf("%lld ", median);
        }
    }
    else // odd
    {
        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            ll median = map[i][M >>1];
            for (int j = 0; j < M; j++)
            {
                ans += ABS(map[i][j] - median);
            }
        }
        printf("%lld\n", ans);
        for (int i = 0; i < N; i++)
        {
            printf("%lld ", map[i][M >>1]);
        }
    }

    return 0;
}