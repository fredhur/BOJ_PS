// Title : 치킨 TOP N https://www.acmicpc.net/problem/11582
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<int> v;
vector<int> ret;
int main()
{
    int N,K;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int num;
        scanf(" %d", &num);
        v.push_back(num);
    }
    scanf(" %d", &K);
    const int s = N/K;
    for(auto &i: v)
    {
        ret.push_back(i);
        if(ret.size() == s)
        {
            sort(ret.begin(), ret.end());
            for(auto &i : ret)
            {
                printf("%d ", i);
            }
            ret.clear();
        }
    }
    puts("");
    return 0;
}