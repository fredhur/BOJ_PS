// Title : 세 수 https://www.acmicpc.net/problem/2985
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    char op[4] = {'+', '-', '*', '/'};
    char ret[2] = {
        0,
    };
    for (int i = 0; i < 4; i++)
    {
        switch (op[i])
        {
        case '+':
            if (a == (b + c))
            {
                ret[0] = '=';
                ret[1] = '+';
                // printf("here");
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
            else if ((a + b) == c)
            {
                ret[0] = '=';
                ret[1] = '+';
                swap(ret[0], ret[1]);
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
            
            break;
        case '-':

            if (a == (b - c))
            {
                ret[0] = '=';
                ret[1] = '-';
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
            else if ((a - b) == c)
            {
                ret[0] = '=';
                ret[1] = '-';
                swap(ret[0], ret[1]);
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
           
            break;
        case '*':
            if (a == (b * c))
            {
                ret[0] = '=';
                ret[1] = '*';
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
            else if ((a * b) == c)
            {
                ret[0] = '=';
                ret[1] = '*';
                swap(ret[0], ret[1]);
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
            
            break;
        case '/':

            if (a == (b / c))
            {
                ret[0] = '=';
                ret[1] = '/';
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
            else if ((a / b) == c)
            {
                ret[0] = '=';
                ret[1] = '/';
                swap(ret[0], ret[1]);
                printf("%d%c%d%c%d", a, ret[0], b, ret[1], c);
                return 0;
            }
            
            break;
        }
    }
    
    return 0;
}