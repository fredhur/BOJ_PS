#include <cstdio>
int main()
{
    int A,B;
    scanf("%d %d", &A, &B);
    const auto val = (A+B) %12;
    printf(val == 0 ? "12\n" :"%d\n", val );
}