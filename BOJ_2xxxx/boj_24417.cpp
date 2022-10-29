// Title : 알고리즘 수업 - 피보나치 수 2 https://www.acmicpc.net/problem/24417
#include <iostream>
int n;
constexpr auto mod = 1'000'000'007;
int func()
{
    if(n==1 || n==2)
    {
        return 1;
    }
    int previousFib = 0, currentFib = 1;
    for(int i=0; i<n-1; i++)
    {
        int newFib = (previousFib%mod + currentFib%mod)%mod;
        previousFib = currentFib%mod;
        currentFib = newFib%mod;
    }
    return currentFib;
}
int main()
{
    scanf("%d", &n);
    printf("%d %d\n", func(), (n > 2) ? n-2 : 1);

}
