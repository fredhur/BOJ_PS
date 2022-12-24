#include <cstdio>
int main()
{
    int w, h;
    scanf("%d %d", &w, &h);
    const auto ret  = (w*h)/24200;

    printf("%d\n", (w*h) % 24200 == 0 ? ret: ret+1 );
    return 0;
}