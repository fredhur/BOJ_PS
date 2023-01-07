#include <iostream>
using namespace std;
using ll = unsigned long long;
int main()
{
    int tc;
    scanf("%d", &tc);
    while (tc--)
    {
        ll lt, wt, le, we;
        scanf(" %lld %lld %lld %lld", &lt, &wt, &le, &we);
        auto space = (lt * wt) <=> (le * we);

        if(is_gt(space))
        {
            puts("TelecomParisTech");
        }
        else if(is_lt(space))
        {
            puts("Eurecom");
        }
        else 
        {
            puts("Tie");
        }
       
        
    }
    return 0;
}