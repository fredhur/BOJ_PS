// Title : 最長昇順連続部分列 (Longest Ascending Contiguous Subsequence) https://www.acmicpc.net/problem/18416
#include <cstdio>
int N;
int arr[105];


bool check(int idx, int len)
{
    for(int i= idx; i< idx+len -1  ; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf(" %d", &arr[i]);
    }

    for(int s = N; s>=1; s--)
    {
        for(int i=1; i<= N-s+1; i++ )
        {
            if(check(i, s))
            {
                printf("%d\n", s);
                return 0;
            }
        }
    }
    printf("1\n");
    return 0;
}