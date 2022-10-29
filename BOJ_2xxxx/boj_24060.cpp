// Title : 알고리즘 수업 - 병합 정렬 1 https://www.acmicpc.net/problem/24060
#include <cstdio>
constexpr auto SIZE = (500'007);
int arr[SIZE];
int tmp[SIZE];
int K;
int N;
int ans = -1;
void chk(int num)
{
    static int cnt = 0;
    cnt++;
    if (cnt == K)
    {
        ans = num;
    }
}
void Merge(int arr[], int s, int m, int e)
{
    int i = s;
    int j = m + 1;
    int k = s;

    while (i <= m && j <= e)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
            chk(tmp[k - 1]);
        }
        else
        {
            tmp[k++] = arr[j++];
            chk(tmp[k - 1]);
        }
    }

    if (i > m)
    {
        for (int i = j; i <= e; i++)
        {
            tmp[k++] = arr[i];
            chk(tmp[k - 1]);
        }
    }
    else
    {
        for (int l = i; l <= m; l++)
        {
            tmp[k++] = arr[l];
            chk(tmp[k - 1]);
        }
    }
    for (int l = s; l <= e; l++)
    {
        arr[l] = tmp[l];
    }
}
void MergeSort(int arr[], int s, int e)
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
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }

    MergeSort(arr, 0, N - 1);
    printf("%d\n", ans);
    return 0;
}