#include <iostream>
using ll = long long;

ll xorSum(ll n)
{
    const ll lut[] = {
        n,
        1,
        n + 1,
        0};
    const auto m = n & (4 - 1);
    return lut[m];
}
ll A, B;
int main()
{
    std::cin >> A >> B;
    const ll ret = xorSum(A - 1) ^ xorSum(B);
    std::cout << ret;
    return 0;
}