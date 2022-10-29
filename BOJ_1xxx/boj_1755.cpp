// Title : 숫자놀이 https://www.acmicpc.net/problem/1755
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int M, N;
string LookUpTbl(int N)
{
    static string lut[10] =
        {
            "zero",
            "one",
            "two",
            "three",
            "four",
            "five",
            "six",
            "seven",
            "eight",
            "nine"};
    return lut[N];
}
struct Data
{
    int num;
    string str1;
    string str2;

    void init()
    {
        if (num > 9)
        {

            str1 = LookUpTbl(num / 10);
            str2 = LookUpTbl(num % 10);
        }
        else
        {
            str1 = LookUpTbl(num % 10);
            str2 = "";
        }
    }
    bool operator <(const Data &rhs) const
    {
        if(str1==rhs.str1 && str2 == rhs.str2)
        {
            return false;
        }
        if(str1 == rhs.str1)
        {
       
            
            return str2 <= rhs.str2;
        }
        else 
        {
           
            return str1 <= rhs.str1;
        }
        return false;
    }
};
vector<Data> v;
int main()
{
    scanf("%d %d", &M, &N);

    for (int i = M; i <= N; i++)
    {
        Data data;
        data.num = i;
        data.init();
       
        v.push_back(data);
    }

    
   std::sort(v.begin(), v.end());
  
    for (int i = 0; i < v.size(); i++)
    {
         if(i % 10 ==0 && i!=0)
        {
            puts("");
        }
        cout <<  v[i].num <<" ";
       
    }puts("");
    return 0;
}