// Title : 제자리 https://www.acmicpc.net/problem/25400
#include <cstdio>
int arr[250007];
int N;
int main()
{
    int del = 0;
    int chk = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }

    for(int i=0; i<N; i++)
    {
        if(arr[i] == chk)
        {
            chk++;
            continue;
        }
        else 
        {
            del++;
        }
    }
    printf("%d\n", del);
    return 0;
}