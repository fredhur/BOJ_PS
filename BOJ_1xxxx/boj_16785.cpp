// Title : ソーシャルゲーム (Social Game) https://www.acmicpc.net/problem/16785
#include <cstdio>
#include <iostream>
#include <cmath>
int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    const int total = 7*A + B;

    const int ret = C/total*7 + std::min((int)ceil((double)(C % total) / (double)A), 7);
    printf("%d\n", ret);
    return 0;
}