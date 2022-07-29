#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> v;
int N;
char str[105];
inline bool IsNum(char a)
{
    return a >= '0' && a <= '9';
}
void ExtractNums(vector<string> &v, const char *str)
{
    for (auto i = 0; str[i]; i++)
    {
        if (IsNum(str[i]))
        {
            int j = i;
            string ret = "";
            int Cnt = 0;
            while (IsNum(str[j]))
            {
                ret += str[j]; 
                j++;
                Cnt++;
            }
            ret.erase(0, min(ret.find_first_not_of('0'), ret.size()-1));
            v.push_back(ret);
            i += Cnt-1;
        }
    }
}

struct MyCmp
{
    bool operator() (const string &a, const string &b) const
    {
        if(a.length() == b.length())
        {
            return a <b;
        }
        else 
        {
            return a.length() <b.length();
        }
    }
};
int main()
{
    scanf("%d", &N);
    while (N--)
    {
        scanf(" %s", str);
        ExtractNums(v, str);
    }

    std::sort(v.begin(), v.end(), MyCmp());
    for (auto &i : v)
    {
        cout << i << '\n';
    }
}