#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
vector<int> v;
using ll = long long;
int main()
{
    scanf("%d", &N);
    ll sum = 0;
    for(int i=0; i<N; i++)
    {
        int p;
        scanf(" %d", &p);
        v.push_back(p);
        
    }
    sort(v.begin(), v.end(), greater<int>());

  
    for(int i=0; i<N; i++)
    {
        if(i%3 ==2) continue;
        
        sum += v[i];
    }
    printf("%lld", sum);

}