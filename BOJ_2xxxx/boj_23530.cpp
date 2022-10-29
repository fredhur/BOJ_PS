// Title : Not A + B https://www.acmicpc.net/problem/23530
#include <cstdio>
int solve(int sum)
{
    for(int i=1; i<=50; i++)
    {
        if(i != sum)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        printf("%d\n", solve(a+b));
    }
    return 0;
}