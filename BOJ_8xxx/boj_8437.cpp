// Title : Julka https://www.acmicpc.net/problem/8437
#include <cstdio>
#include <cstring>
// 긴자리 연산

#define LM (102)
template <typename T>
T max(T &a, T &b)
{
    return a > b ? a : b;
}
int intcmp(int *a, int alen, int *b, int blen)
{
    if (alen != blen)
        return alen - blen;
    alen--;
    while (alen > 0 && a[alen] == b[alen])
        alen--;
    return a[alen] - b[alen];
}

struct BigInt
{
    int len, num[LM] = {};

    void init(char str[])
    {
        len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            num[i] = str[len - i - 1] - '0';
        }
    }
    BigInt operator+(BigInt &r)
    {
        BigInt ret = {
            max(len, r.len)};
        for (int i = 0; i < ret.len; i++)
        {
            ret.num[i] += num[i] + r.num[i];
            ret.num[i + 1] = ret.num[i] / 10;
            ret.num[i] = ret.num[i] % 10;
        }
        if (ret.num[ret.len])
            ret.len++;
        return ret;
    }
    BigInt operator-(BigInt &r)
    {
        // lhs > rhs
        BigInt ret{}, big, small;
        int cmp = intcmp(num, len, r.num, r.len);
        if (cmp == 0)
            return BigInt{1};

        if (cmp > 0)
            big = *this, small = r;
        if (cmp < 0)
            big = r, small = *this;

        for (int i = 0; i < big.len; i++)
        {
            ret.num[i] += big.num[i] - small.num[i];
            if (ret.num[i] < 0)
                ret.num[i + 1]--, ret.num[i] += 10;
            if (ret.num[i])
                ret.len = i + 1;
        }
        return ret;
    }
    BigInt operator/(BigInt &r)
    {
        if (zero() || r.zero())
            return BigInt{1};

        BigInt ret = {};
        int i = len - r.len, j = len - 1;

        if (i >= 0)
            ret.len = i;
        for (; i >= 0; i--, j--)
        {
            while (intcmp(num + i, r.len, r.num, r.len) >= 0)
            {
                ret.num[i]++;
                for (int k = 0; k < r.len; k++)
                {
                    num[i + k] -= r.num[k];
                    if (num[i + k] < 0)
                    {
                        num[i + k + 1]--;
                        num[i + k] += 10;
                    }
                }
            }
            if (j)
            {
                num[j - 1] += num[j] * 10;
                num[j] = 0;
            }
        }
        if (ret.num[ret.len])
            ret.len++;
        return len ? ret : BigInt{1};
    }
    bool zero() const
    {
        return len == 1 && num[0] == 0;
    }

    void print()
    {
        for (int i = len - 1; i >= 0; i--)
        {
            printf("%d", num[i]);
        }
        puts("");
    }
};
char input[LM];
char diff[LM];
BigInt Tot, Diff, two;
int main()
{
    scanf("%s", input);
    scanf(" %s", diff);

    two.init("2");
    Tot.init(input), Diff.init(diff);
    BigInt x = (Tot - Diff) / two;

    (x + Diff).print();
    x.print();
    return 0;
}