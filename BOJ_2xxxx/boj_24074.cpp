// Title : 分割 (Split) https://www.acmicpc.net/problem/24074
#include <cstdio>
int N;
int arr[105];

int CalcMaxNumIdx(int (&arr)[105])
{

    int ret = arr[0];
    int idx = 0;
    for (int i = 0; i < N; i++)
    {
        if (ret < arr[i])
        {
            ret = arr[i];
            idx = i;
        }
    }
    return idx;
}
int main()
{

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }

    int idx = CalcMaxNumIdx(arr);

    auto backSum = 0;
    auto frontSum = 0;
    for (int i = 0; i < idx; i++)
    {
        frontSum += arr[i];
    }

    for (int i = idx + 1; i < N; i++)
    {
        backSum += arr[i];
    }
    printf("%d\n%d\n", frontSum, backSum);

    return 0;
}