// Title : 부분 문자열 https://www.acmicpc.net/problem/16916
#include <iostream>

template <typename T>
T Max(T a, T b)
{
    return a > b ? a : b;
}

struct Data
{
    int tab;
    int blank;
} members[400];
int N;

int CalcBookDay()
{
    int ans = 0;

    for (int i = 0; i < std::size(members); i++)
    {
        ans+=(members[i].tab > 0 || members[i].blank > 0);
    }
    return ans;
}
int CalcMaxPeople()
{
    int ans = -1;
    for (int i = 0; i < std::size(members); i++)
    {
        ans = Max(members[i].tab + members[i].blank, ans);
    }
    return ans;
}
int NoFightDay()
{
    int ans = 0;
    for (int i = 0; i < std::size(members); i++)
    {
        ans += ((members[i].tab == members[i].blank) && (members[i].tab * members[i].blank != 0));
    }
    return ans;
}
int CalcComplicatedCondition()
{
    int ans = 0;
    for (int i = 0; i < std::size(members); i++)
    {
        if (members[i].tab == members[i].blank)
        {
            ans = Max(ans, members[i].tab + members[i].blank);
        }
    }
    return ans;
}

int main()
{
    scanf("%d", &N);
    auto maxDay = -1;
    while (N--)
    {
        char c;
        int s, e;
        scanf(" %c %d %d", &c, &s, &e);
        maxDay = Max(maxDay, e - s + 1);
        if (c == 'T')
        {
            for (int i = s; i <= e; i++)
            {
                members[i].tab++;
            }
        }
        else if (c == 'S')
        {
            for (int i = s; i <= e; i++)
            {
                members[i].blank++;
            }
        }
    }
    printf("%d\n", CalcBookDay());
    printf("%d\n", CalcMaxPeople());
    printf("%d\n", NoFightDay());
    printf("%d\n", CalcComplicatedCondition());
    printf("%d\n", maxDay);
    return 0;
}
