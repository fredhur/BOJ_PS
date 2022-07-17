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
