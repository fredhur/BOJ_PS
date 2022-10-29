// Title : 이항 계수 3 https://www.acmicpc.net/problem/11401
#include <iostream>
using namespace std;
using ll = long long;
constexpr auto DIV = 1'000'000'007;
ll power(ll a, ll m)
{
    ll temp;
    if (m == 0)
        return 1;
    temp = power(a, m / 2) % DIV;
    if (m % 2 == 1)
        return temp * temp % DIV * a % DIV;
    return temp * temp % DIV;
}

void solve(int n, int k)
{
    if (k == 1)
    {
        cout << n;
        return;
    }
    if (k == 0 || n == k)
    {
        puts("1");
        return;
    }
    if (n - k == 1)
    {
        cout << n;
        return;
    }

    ll A = 1, B = 1, ans;
    for (int i = n; i >= n - k + 1; i--)
        A = (A * i) % DIV;
    for (int i = 1; i <= k; i++)
        B = (B * i) % DIV;
    ans = ((A % DIV) * power(B, DIV - 2) % DIV) % DIV;
    cout << ans;
}

int main(void)
{
    int n, k;

    scanf("%d %d", &n, &k);
    solve(n, k);

    return 0;
}