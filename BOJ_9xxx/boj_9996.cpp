// Title : 한국이 그리울 땐 서버에 접속하지 https://www.acmicpc.net/problem/9996
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string str, char Delimiter)
{
    istringstream iss(str); // istringstream에 str을 담는다.
    string buffer;          // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter))
    {
        result.push_back(buffer); // 절삭된 문자열을 vector에 저장
    }

    return result;
}
bool Lcmp(string &ref, string &left)
{
    const auto leftLen = left.length();
    for (int i = 0; i < leftLen; i++)
    {
        if (ref[i] != left[i])
        {
            return false;
        }
    }
    return true;
}
bool Rcmp(string &ref, string &right)
{
    const auto rightLen = right.length();
    const auto refLen = ref.length();
    for (int i = 0; i < rightLen; i++)
    {
        if (ref[refLen - i - 1] != right[rightLen - i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int N;
    cin >> N;
    string ref;
    cin >> ref;
    vector<string> sp = split(ref, '*');
    const auto llen = sp[0].length();
    const auto rlen = sp[1].length();
    while (N--)
    {
        string str;
        cin >> str;
        if (str.length() < llen + rlen)
        {
            puts("NE");
        }
        else
        {
            const bool l = Lcmp(str, sp[0]);
            const bool r = Rcmp(str, sp[1]);
            puts(l && r ? "DA" : "NE");
        }
    }
}