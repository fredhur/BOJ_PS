#include <cstdio>
bool isJOI(char *s)
{
    if (s[0] == 'j' && s[1] == 'o' && s[2] == 'i')
    {
        return true;
    }
    return false;
}

int main()
{
    int N;
    char str[105];
    scanf("%d %s", &N, str);
    for (int i = 0; i < N;)
    {
        if (i <= N - 3 && isJOI(&str[i]))
        {
            printf("JOI");
            i += 3;
            continue;
        }
        else
        {
            printf("%c", str[i]);
            i++;
        }
    }
    puts("");
}