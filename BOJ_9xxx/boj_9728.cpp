#include <iostream>
int Solve(const int &N, const int &M)
{
    // two Pointer
    static int arr[20005];
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }
    int start = 0, end = N-1, ans=0;
    long long sum = arr[0] + arr[N-1];
    ans += (sum == M);
    while(start != end)
    {
        if(sum > M)
        {
            sum -= arr[end--];
            sum+=arr[end];
        }
        else 
        {
            sum -= arr[start++];
            sum += arr[start];
        }
        ans += (sum==M);
    }
    return ans;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    for (int testCase = 1; testCase <= tc; testCase++)
    {
        int N, M;
        scanf(" %d %d", &N, &M);
        printf("Case #%d: %d\n", testCase, Solve(N,M));
    }
    return 0;
}