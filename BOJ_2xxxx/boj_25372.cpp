// Title : 성택이의 은밀한 비밀번호 https://www.acmicpc.net/problem/25372
#include <iostream>
const char *Calc(char *pwd)
{

    auto isOkay = [](const int &len)
    { return len >= 6 && len <= 9; };
    auto mstrlen = [](char *s)
    {  int i = 0;
        for (i = 0; s[i]; i++);
        return i; };
    return isOkay(mstrlen(pwd)) ? "yes" : "no";
}
int main()
{
    int N;
    char str[22];
    scanf("%d", &N);
    while (N--)
    {
        scanf(" %s", str);
        printf("%s\n", Calc(str));
    }
}