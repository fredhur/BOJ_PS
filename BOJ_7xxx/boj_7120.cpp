// Title : String https://www.acmicpc.net/problem/7120
#include <cstdio>
char str[252];
auto mstrlen(char *s)
{
    int i;
    for (i = 0; s[i]; i++);
    return i;
}
int main()
{
    scanf("%s", str);
    printf("%c", str[0]);

    if (mstrlen(str) == 1)
    {
        puts("");
        return 0;
    }
    else
    {
        for (int i = 1; str[i]; i++)
        {
            if (str[i] != str[i - 1])
            {
                printf("%c", str[i]);
            }
        }
    }
    puts("");
    return 0;
}