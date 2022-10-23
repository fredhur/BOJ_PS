#include <cstdio>
int mstrlen(char *s)
{
    int i=0;
    for(i=0; s[i]; i++);
    return i;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        char str[105];
        int ans = 0;
        scanf(" %s", str);
        for (int i = 0; str[i]; i++)
        {
            if(str[i]=='D') str[i] = '\0';   
        }
        printf("%d\n", mstrlen(str));
    }
    return 0;
}