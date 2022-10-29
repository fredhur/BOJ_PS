// Title : Tournament Selection https://www.acmicpc.net/problem/14038
#include <cstdio>
constexpr short lut[] =
    {
        -1,
        3,
        3,
        2,
        2,
        1,
        1};
int main()
{
    char ch;
    short ret = 0;
     scanf("%c", &ch);
     ret += (ch == 'W');
    for (auto i = 0; i < 5; i++)
    {
        
        scanf(" %c", &ch);
        ret += (ch == 'W');
    }
    printf("%d", lut[ret]);
}