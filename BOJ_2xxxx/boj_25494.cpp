#include <cstdio>
int ans(const int &a, const int &b, const int &c)
{
    int ans =0;

    for(int i=1; i<=a ; i++)
    {
        for(int j=1; j<=b; j++)
        {
            for(int k=1; k<=c; k++)
            {
                if(((i%j)== (j%k)) &&( (j%k ==0 && k %i==0)))
                {
                    ans++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf("%d\n", ans(a,b,c));

    }
    return 0;
}