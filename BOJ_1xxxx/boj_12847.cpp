#include <cstdio>

using ll = long long;


int main()
{
    ll arr[100'007];
    int n, m;
    scanf("%d %d", &n, &m);
    
    
    for(int i=0; i<n; i++)
    {
       scanf(" %lld", &arr[i]);
    }
    ll money =0;
    for(int i=0; i<m; i++)
    {
        money += arr[i];
    }
    ll ans = money;
    for(int i=0; i<n-m; i++)
    {
        ll t = money -arr[i] + arr[i+m];
        ans = ans < t ? t : ans;
        money = t;
    }

    printf("%lld", ans);
    return 0;
}