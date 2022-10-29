// Title : 영수증 https://www.acmicpc.net/problem/25304
#include <iostream>
using ll = long long;
class Solve
{
public:
    Solve() = default;
    Solve(const int &X, const int &N) : X_(X),
                                        N_(N)
    {
        sum_ = 0;
    }
    ~Solve() = default;

    void Add(const int &a, const int &b)
    {
        sum_ += (a * b);
    }
    const char *CheckEqual()
    {
        return sum_ == X_ ? "Yes" : "No";
    }

private:
    const int X_;
    const int N_;
    ll sum_;
};
int main()
{
    int X, N;
    scanf("%d", &X);
    scanf(" %d", &N);
    Solve solve(X, N);

    for (int i = 0; i < N; i++)
    {
        int a, b;
        scanf(" %d %d", &a, &b);
        solve.Add(a, b);
    }
    printf("%s", solve.CheckEqual());
}