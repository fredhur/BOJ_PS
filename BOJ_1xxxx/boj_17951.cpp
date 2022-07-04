// binary search optimization.
#include <cstdio>
int N, K, ans, low, high, arr[100007];
bool check(int mid)
{
    int gcnt = 0;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum >= mid)
        {
            gcnt++;
            sum = 0;
        }
    }
    return gcnt >= K;
}
void bsearch()
{
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}
int main()
{
    scanf("%d %d", &N, &K);
    low = 0x7fffffff;
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
        if (low >= arr[i])
            low = arr[i];
        high += arr[i];
    }

    bsearch();
    printf("%d", ans);
}