// Title : 안정적인 문자열 https://www.acmicpc.net/problem/4889
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
int ans;

char str[2500];
auto strLen(char (&str)[2500])
{
    auto i = 0;
    for (i = 0; str[i] != '\0'; i++)
        ;
    return i;
}
int main()
{
    int idx = 0;
    while (true)
    {
        scanf("%s", str);
        getchar();
        if (str[0] == '-')
            break;

        stack<char> stk;
        ans = 0;
       

        for (auto i = 0; i < strLen(str); i++)
        {

            if (str[i] == '{')
            {
                stk.push('{');
            }
            else
            {
                if (!stk.empty())
                {
                    stk.pop();
                }
                else
                {
                    ans++;
                    stk.push('{');
                }
            }
        }
        if (stk.empty())
        {
            printf("%d. %d\n", ++idx, ans);
        }
        else
        {
            printf("%d. %d\n", ++idx, ans + stk.size() / 2);
        }
    }

    return 0;
}