// Title : Caesar Word Salad https://www.acmicpc.net/problem/20355
#include <cstdio>
int CalcCaesarStr(char *str)
{
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        int icnt = 0;
        for (int j = 0; str[j]; j++)
        {
            const auto ch = ((str[j]-'a' + i) % 26) + 'a';
            icnt += (ch=='i');
        }
        cnt += (icnt == 0);
       
    }
    return cnt;
}
int main()
{
    char str[105];
    scanf("%s", str);
    const auto ret = CalcCaesarStr(str);
    if(ret ==0)
    {
        puts("impossible");
    }
    else 
    {
        printf("%d",ret);
    }
    return 0;
}
