#include <cstdio>

int arr[100'003];
int N, M;
bool chk(const int size)
{

    int groupCnt = 1;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (sum + arr[i] > size)
        {
            sum = arr[i];
            groupCnt++;
        }
        else
        {
            sum += arr[i];
        }
    }

    return groupCnt <= M;
}

int bsearch(int min)
{
    int low = min;
    int high = 1000000;
    int ans = min;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (chk(mid)) // 조건보다 더  갯수 좀 더 늘리는거 체크 그걸 위해서는 크기를 좀더 작ㅔ
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
int main()
{

    scanf("%d %d", &N, &M);
    int min = 0;
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
        min = min < arr[i] ? arr[i] : min;
    }

    printf("%d\n", bsearch(min));

    return 0;
}