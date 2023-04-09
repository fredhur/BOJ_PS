#include <cstdio>
#include <algorithm>
constexpr auto SIZE = 100'007;
int arr[SIZE];
int tmp[SIZE];
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
int N, M;

int LowerBound(int target)
{
    int low = 0, high = N - 1;
    int ans = 01;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (target <= arr[mid])
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int UpperBound(int target)
{
    int left = 0, right = N - 1, mid;
    int upper_bnd = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] <= target)
        {
            upper_bnd = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return upper_bnd + 1 >= N ? -1 : upper_bnd + 1;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }

    MergeSort(arr, 0, N - 1);
    for (int i = 0; i < M; i++)
    {
        int left, right;
        scanf(" %d %d", &left, &right);
        int leftIdx = std::lower_bound(arr, arr+N, left) - arr;
        int rightIdx = std::upper_bound(arr, arr+N ,right) -arr;
        // printf("(%d %d)\n", leftIdx, rightIdx);

        printf("%d\n", -leftIdx + rightIdx);
    }
    return 0;
}