#include <cstdio>
int bucket[16];
int screen[16];
int J, N, M, ans;
int calc(int &l, int &r, int &apple)
{
    if (r < apple)
    {
        const int d = apple - r;
        r += d;
        l += d;
        return d;
    }
    else if (l <= apple && r >= apple)
    {
        return 0;
    }
    else if (apple < l)
    {
        const int d = l - apple;
        r -= d;
        l -= d;
        return d;
    }
    else
        return 0;
}
int main()
{

    scanf("%d %d", &N, &M);
    scanf(" %d", &J);
    int l = 1;
    int r = M;
    while (J--)
    {
        int apple;
        scanf(" %d", &apple);
        ans += calc(l, r, apple);
    }
    printf("%d", ans);
}