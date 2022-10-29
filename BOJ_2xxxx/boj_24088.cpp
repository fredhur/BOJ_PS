// Title : 運動会 (Sports Day) https://www.acmicpc.net/problem/24088
#include <cstdio>
int N;
int K;
char str[2005];
int main()
{
    scanf("%d", &N);
    scanf(" %d", &K);
    scanf(" %s", str);
    int R = 0, W = 0;
    for (int i = 0; str[i]; i++)
    {
        R += str[i] == 'R';
        W += str[i] == 'W';
    }
    puts(R == K ? "W" : "R");

    return 0;
}