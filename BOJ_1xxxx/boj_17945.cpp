// Title : 통학의 신 https://www.acmicpc.net/problem/17945
#include <cstdio>
class Solve
{
public:
    void solve()
    {
        scanf("%d %d", &A, &B);
        auto D = sqrt(A * A - B);
        if (D == 0) printf("%d", -A);
        else printf("%d %d", -D - A, D - A);
    }
private:
    int sqrt(int n)
    {
        int s = 1, e = n;
        int ans = n;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (m <= n / m)
                s = m + 1, ans = m;
            else
                e = m - 1;
        }
        return ans;
    }int A,B;
}s;
int main()
{
    s.solve();
}