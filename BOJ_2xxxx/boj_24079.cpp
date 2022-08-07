#include <cstdio>
int main()
{
    int X,Y,Z;
    scanf("%d%d%d",&X,&Y,&Z);
    puts(((X+Y)<<1)<=((Z<<1)+1)?"1":"0");
}