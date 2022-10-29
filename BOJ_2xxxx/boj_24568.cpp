// Title : Cupcake Party https://www.acmicpc.net/problem/24568
#include <cstdio>
int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    a = a*8 + b*3;
    printf("%d\n", a-28);
}