// Title : K번째 수 https://www.acmicpc.net/problem/1300
#include <cstdio>
using ll = long long;
template <typename T>
inline T MIN(const T a, const T b)
{
    return a < b ? a : b;
}
ll N, K;
ll Bsearch(ll s, ll e)
{
    ll ans = 0;
    while (s <= e)
    {
        ll mid = (s + e) / 2, cnt = 0;
        for (int i = 1; i <= N; i++) cnt += MIN(mid / i, N);
        
        if (cnt >= K)
        {
            e = mid - 1;
            ans = mid; 
        } 
        else 
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    scanf("%lld %lld", &N, &K);
    printf("%lld", Bsearch(1, N * N));
}