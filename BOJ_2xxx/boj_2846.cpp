#include <cstdio>
int arr[1003];
int s, e, ans;
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }

    while (e < N)
    {
        s = e;

        while (arr[e] < arr[e + 1])
        {
            e++;
        }

        const auto r = arr[e] - arr[s];

        ans = r > ans ? r : ans;
        
        e++;
    }
    printf("%d", ans);
    return 0;
}