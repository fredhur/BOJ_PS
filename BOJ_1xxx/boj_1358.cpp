// Title : 하키 https://www.acmicpc.net/problem/1358
#include <cstdio>
// think it as X,Y axis.
int W, H, X, Y, P, radius;
int ans;
int main()
{
    scanf("%d%d%d%d%d", &W, &H, &X, &Y, &P);
    radius = H/2;
    for(auto i=0; i<P; i++)
    {
        int x,y;
        scanf(" %d%d", &x, &y);
        if(0<=x-X && x-X <=W && 0<=y-Y && y-Y <= H)
        {
            ans++;
            continue;
        }
        else 
        {
            auto pX = x-X;
            auto pY = y-Y -radius;
            if(pX <=0 && pX*pX + pY*pY <= radius*radius)
            {
                ans++;
                continue;
            }
            pX -=W;
            if(pX >=0 && pX*pX + pY*pY <= radius*radius)
            {
                ans++;
                continue;
            }
        }
    }
    printf("%d", ans);
}