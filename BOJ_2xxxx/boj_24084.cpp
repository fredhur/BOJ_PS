// Title : 次の文字 (Next Character) https://www.acmicpc.net/problem/24084
#include <cstdio>
int main()
{
    int N;
    char str[104];
    scanf("%d", &N);
    scanf(" %s", str);
    for (int i = 0; i < N - 1; i++)
    {
        if(str[i+1] == 'J')
        {
            printf("%c\n", str[i]);
        }
    }
}