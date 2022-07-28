#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int> v;
vector<int> diff;
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
    {
        int p;
        scanf(" %d", &p);
        v.push_back(p);
    }
    sort(v.begin(),v.end());

    const int len = v.size()/K;
    
    for(int i=0; i<v.size()-1; i++)
    {
        diff.push_back(v[i+1]-v[i]);
    }
    sort(diff.begin(), diff.end(), greater<int>());

    auto dif = v[N-1]-v[0];
    for(auto i=0; i<K-1; i++)
    {
        dif -= diff[i];
    }
    printf("%d", dif);

}