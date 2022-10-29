// Title : 팰린드롬 만들기 https://www.acmicpc.net/problem/1213
#include <iostream>
char str[55];
int charactersCnt[26];
int mstrlen(char *s)
{
    int i = 0;
    for (i = 0; s[i]; i++)
        ;
    return i;
}
bool ChkPossible()
{
    int even = 0;
    int odd = 0;
    for (int i = 0; i < std::size(charactersCnt); i++)
    {
        const bool cnt = (charactersCnt[i] % 2 == 0);
        even += cnt;
        odd += !cnt;
    }
    return odd > 1 ? false : true;
}
void MakePalindrome(char str[])
{
    char palindrome[55];
    int len = mstrlen(str);
    int pPos = 0;
    for (int i = 0; i < std::size(charactersCnt); i++)
    {
        if (charactersCnt[i] % 2 == 1)
        {
            palindrome[len / 2] = i + 'A';
            charactersCnt[i]--;
        }
    }

    for (int i = 0; i < std::size(charactersCnt); i++)
    {
        while (charactersCnt[i] > 0)
        {
            palindrome[pPos] = i + 'A';
            palindrome[len - pPos - 1] = i + 'A';
            pPos++;
            charactersCnt[i] -= 2;
        }
    }
    palindrome[len] = '\0';
    printf("%s", palindrome);
}
void input()
{
    scanf("%s", str);
}
void MakeLut()
{
    for (int i = 0; str[i]; i++)
    {
        charactersCnt[str[i] - 'A']++;
    }
}
void solve()
{
    if (ChkPossible() == false)
    {
        puts("I'm Sorry Hansoo");
    }
    else
    {
        MakePalindrome(str);
    }
}
int main()
{
    input();
    MakeLut();
    solve();
    return 0;
}
