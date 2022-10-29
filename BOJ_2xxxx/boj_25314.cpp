// Title : 코딩은 체육과목 입니다 https://www.acmicpc.net/problem/25314
#include <cstdio>

int main()
{
    const char strLong[] = "long", strInt[] = "int";
    int N;
    scanf("%d", &N);
    N = (N>>2);
    while (N--)
    {
        printf("%s ", strLong);
    }
    printf("%s", strInt);
}
