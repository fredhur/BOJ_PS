// Title : 1 https://www.acmicpc.net/problem/4375
#include <iostream>
using namespace std;
using ll = long long;
ll m;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    m = 1;
    while (cin >> n)
    {
        int cnt = 1;
        while (m % n != 0)
        {
            m = m % n;
            m = m * 10 + 1;
            cnt++;
        }
        cout << cnt << '\n';
        m = 1;
    }
}