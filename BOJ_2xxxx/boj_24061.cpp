// Title : 알고리즘 수업 - 병합 정렬 2 https://www.acmicpc.net/problem/24061
#include <iostream>
using namespace std;
constexpr auto SIZE = 500007;
int N, K;
int arr[SIZE];
int sorted[SIZE];
int cnt = 0;

void Merge(int s, int m, int e)
{
    int i = s;
    int j = m + 1;
    int k = s;
    while (i <= m && j <= e)
    {
        if (arr[i] < arr[j])
        {
            sorted[k++] = arr[i];
            i++;
        }
        else
        {
            sorted[k++] = arr[j];
            j++;
        }
    }
    if (i > m)
    {
        for (int i = j; i <= e; i++)
        {
            sorted[k++] = arr[i];
        }
    }
    else
    {
        for (int l = i; l <= m; l++)
        {
            sorted[k++] = arr[l];
        }
    }

    for (int i = s; i <= e; i++)
    {
        arr[i] = sorted[i];
        if (++cnt == K)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", arr[j]);
            }
            puts("");
            exit(0);
        }
    }
}

void MergeSort(int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        MergeSort(s, m);
        MergeSort(m + 1, e);
        Merge(s, m, e);
    }
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }
    MergeSort(0, N - 1);
    if (cnt < K)
    {
        puts("-1");
    }

    return 0;
}
