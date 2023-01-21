#include <cstdio>
void Ans(int N)
{
    const int five = N / 5;
    const int one = N % 5;
    for (int i = 0; i < five; i++)
    {
        printf("V");
    }
    for (int i = 0; i < one; i++)
    {
        printf("I");
    }
    return;
}
int main()
{
    int N;
    scanf("%d", &N);
    Ans(N);
    return 0;
}