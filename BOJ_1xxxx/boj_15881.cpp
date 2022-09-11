#include <cstdio>
int N;
char str[1000007];
int main()
{
    scanf("%d", &N);
    scanf(" %s", str);

    int i=0;
    int ans = 0;
    while(i<N)
    {
        if(str[i]=='p' && str[i+1]=='P' && str[i+2]=='A' && str[i+3]=='p')
        {
            ans++;
            i+=4;
        }
        else 
        {
            i++;
        }
    }
    printf("%d\n", ans);
    return 0;
}