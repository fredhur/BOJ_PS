// Title : 帰省 (Homecoming) https://www.acmicpc.net/problem/24072
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool chk = (c - a >= 0) && (b - c > 0);
    cout << chk;
}