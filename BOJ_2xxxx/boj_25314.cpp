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
