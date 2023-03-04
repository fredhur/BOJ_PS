#include <cstdio>
using ll = unsigned int;


int main()
{
    int tc;
  
    scanf("%d", &tc);
    
    while(tc--)
    {
        int x, y;
        scanf(" %d %d", &x, &y);
        ll n = y-x ;
        
        // an = an-1 + n/2 ( n>=2)
        ll boundNum = 1;
        int cnt =0;
        for(ll idx=2; boundNum < n ; idx++)
        {
            boundNum += (idx/2);
            cnt++;
        }
       
        
        if(boundNum > n)
        {
            cnt--;
        }
        printf("%d\n", cnt+1);
    }
    
    return 0;
}