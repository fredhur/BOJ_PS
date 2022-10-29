// Title : 단어 맞추기 https://www.acmicpc.net/problem/9081
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        string str, prevStr;
        cin >> str;
        prevStr = str;
        if(next_permutation(str.begin(), str.end())) cout << str << '\n';
        else cout << prevStr << '\n';
    }
}