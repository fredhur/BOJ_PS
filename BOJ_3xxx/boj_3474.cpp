#include <cstdio>
int LeadingZero(int n)
{
    auto ans = 0;
    auto div = 5;
    auto tmp = n;
    while(tmp>0)
    {
        tmp = n/div;
        ans += tmp;
        div = div * 5;
    }
    return ans;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        scanf(" %d", &n);
        printf("%d\n", LeadingZero(n));
    }
    return 0;
}