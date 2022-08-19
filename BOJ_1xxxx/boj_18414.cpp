#include <cstdio>
int X,L,R;
int main()
{
    scanf("%d %d %d", &X, &L, &R);

    if(X >= R) 
    {
        printf("%d\n", R);
    }
    else if(X <= L)
    {
        printf("%d", L);
    }
    else 
    {
        printf("%d\n", X);
    }

    return 0;
}