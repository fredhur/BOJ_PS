#include <cstdio>
using ll = long long;
int main()
{
    ll N;
    scanf("%lld", &N);
    bool who = (N % 7 == 0 || N % 7 == 2);
    
    puts(who ? "CY" : "SK");
    
    return 0;
}