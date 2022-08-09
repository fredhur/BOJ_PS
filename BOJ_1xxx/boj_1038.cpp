#include <iostream>
#include <vector>
#include <algorithm>
int N;
using ll = long long;
using namespace std;
vector<ll> v;
int main()
{
    scanf("%d", &N);
    for(int i=1; i<=1023; i++)// 감소하는 수 다 구한후 sort
    {
        ll n = 0;
        auto init = i;
        for(int j=9; j>=0; j--)
        {
            if(init %2 == 1)
            {
                n = n*10 + j;
            }
            init = init/2;
        }
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    if(N>1022)
    {
        puts("-1");
    }
    else 
    {
        printf("%lld", v[N]);
    }
    return 0;
}