#include <cstdio>
int N;
int threeSquare(int a, int N)
{
    if (N == 0)
        return 1;

    if (N == 1)
        return a;

    auto tmp = threeSquare(a, N / 2);
    if (N % 2 == 0)
        return tmp * tmp;
    else
        return a * tmp * tmp;
}
void KantoreString(int numIdx, int len)
{

    if (len == 1)
    {
        printf("-");
        return;
    }
    KantoreString(numIdx, len / 3);

    for (int i = 0; i < len / 3; i++)
        printf(" ");

    KantoreString(numIdx + 2 * len / 3, len / 3);
}
int main()
{
    while (scanf("%d", &N) != EOF)
    {
        KantoreString(0, threeSquare(3, N));
        puts("");
    }
    return 0;
}