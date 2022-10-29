// Title : 로프 https://www.acmicpc.net/problem/2217
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector<int> v;
int main()
{
    scanf("%d", &N);
    while(N--)
    {
        int num;
        scanf(" %d", &num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    int cnt =1;
    int ans = 0;
    for(int i=v.size()-1; i>=0; i--)
    {   
        ans = std::max(ans, v[i]*(cnt++));
    }
    printf("%d\n", ans);
    return 0;
}