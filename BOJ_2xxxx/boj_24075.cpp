#include <iostream>
using namespace std;
using stdint = int32_t;
template <typename T>
void maxSwap(T &a, T &b)
{
    if (a < b)
    {
        T t = a;
        a = b, b = t;
        return;
    }
}
int main()
{
    stdint a, b;
    cin >> a >> b;

    int c = a + b, d = a - b;
    maxSwap(c, d);
    cout << c << '\n'
         << d << '\n';
}