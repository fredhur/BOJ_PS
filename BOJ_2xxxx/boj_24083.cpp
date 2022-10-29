// Title : 短針 (Hour Hand) https://www.acmicpc.net/problem/24083
#include <cstdio>
int main()
{
    int A, B;
    scanf("%d %d", &A, &B);
    const auto val = (A + B) % 12;
    printf(val == 0 ? "12\n" : "%d\n", val);
}