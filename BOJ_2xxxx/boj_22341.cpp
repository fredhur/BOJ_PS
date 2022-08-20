#include <cstdio>
int main()
{
    int N, C, w, h;
    scanf("%d %d", &N, &C);
    w=N,h=N;
    for(int i=0; i<C; i++)
    {
        int x, y;
        scanf(" %d %d", &x, &y);

        if(x >=h || y>=w) continue;

        auto s1 = x*w;
        auto s2 = y*h;

        if(s1 >= s2)
        {
            h = x;
        }
        else
        {
            w = y;
        }
       
    }
    printf("%d\n", w * h);
}