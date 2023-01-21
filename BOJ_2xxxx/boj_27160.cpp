#include <iostream>
using UI = unsigned int;
enum Card
{
    STRAWBERRY,
    BANANA,
    LIME,
    PLUM
};

UI HashingStr(const char *str)
{
    const char ch = str[0];

    switch (ch)
    {
    case 'S':
        return 0;
    case 'B':
        return 1;
    case 'L':
        return 2;
    case 'P':
        return 3;
    }
    return 0;
}

int lut[4];

const char *GetAns(int (&lut)[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (lut[i] == 5)
        {
            return "YES";
        }
    }
    return "NO";
}
int main()
{
    int N, X;
    char str[12];
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf(" %s %d", str, &X);
        lut[HashingStr(str)] += X;
    }
    puts(GetAns(lut));
}