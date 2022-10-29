// Title : 17배 https://www.acmicpc.net/problem/5893
#include <cstdio>
template <typename T, size_t N>
constexpr auto MyArrSize(T (&arr)[N])
{
    return N;
}
auto mstrlen(const char *str)
{
    int i = 0;
    for (i = 0; str[i]; i++)
        ;
    return i;
}
template <typename T>
T Max(T &a, T &b)
{
    return a > b ? a : b;
}
const char *Add4Zero(const char *str)
{
    static char s[1020];
    int i = 0;
    for (i = 0; i < mstrlen(str); i++)
    {
        s[i] = str[i];
    }
    s[i++] = '0';
    s[i++] = '0';
    s[i++] = '0';
    s[i++] = '0';
    s[i] = '\0';
  
    return s;
}
class BigInt
{
public:
    BigInt(const char *numArr)
    {
        for (auto i = 0; i < MyArrSize(num); i++)
        {
            num[i] = 0;
        }
        int j = 0;
        len = mstrlen(numArr);
        for (auto i = len - 1; i >= 0; i--)
        {
            // reverse order save.
            num[j++] = numArr[i] - '0';
        }
    }
    BigInt()
    {
        for (auto i = 0; i < MyArrSize(num); i++)
        {
            num[i] = 0;
        }
        len = 0;
    }
    ~BigInt() = default;
    BigInt operator+(const BigInt &rhs) const
    {
        BigInt ret{};
        auto maxLen = Max(len, rhs.len);

        int carry = 0;
        ret.len = maxLen;
        for (int i = 0; i < maxLen; i++)
        {
            auto r = num[i] + rhs.num[i] + carry;

            carry = r >= 2;
            ret.num[i] = r % 2;
        }
        if (carry > 0)
        {
            ret.num[ret.len] = 1;
            ret.len++;
        }
        return ret;
    }
    void Print()
    {
        for (int i = len - 1; i >= 0; i--)
        {
            printf("%d", num[i]);
        }
        puts("");
    }

private:
    int num[1007];
    int len;
};
char str[1005];
int main()
{
    scanf("%s", str);
    BigInt org(str);
    BigInt orgAdd4Zero(Add4Zero(str));

    (org + orgAdd4Zero).Print();
}