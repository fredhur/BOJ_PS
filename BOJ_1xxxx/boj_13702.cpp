#include <cstdio>
int N, K;
int bottle[10007];
int tmp[10007];
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
bool chk(int mid)
{
    int cnt =0;
    for(int i=0; i<N; i++)
    {
        cnt += (bottle[i] / mid);
    }
    return cnt >= K;
}
int bSearch()
{
    int low = 1, high = bottle[N - 1];
    int ans =high;
    while (low <= high)
    {
        int mid = low + (high-low)/2;
       
        if(chk(mid)) // 더 나누어줄 수 있으면 나눠주는 용량을 줄어야함
        {
            low = mid+1;
            ans = mid;
        }else 
        {
            high = mid-1;
        }
    }
    return ans;
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &bottle[i]);
    }
    MergeSort(bottle, 0, N - 1);

    printf("%d", bSearch());
    return 0;
}