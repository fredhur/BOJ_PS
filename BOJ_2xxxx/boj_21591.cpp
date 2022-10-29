// Title : Laptop Sticker https://www.acmicpc.net/problem/21591
#include <cstdio>

int main()
{
    int wc, hc, ws, hs;
    scanf("%d%d%d%d", &wc,&hc,&ws,&hs);
    const bool ret = ((wc - ws) >= 2) && ((hc - hs) >= 2);

    puts(ret ? "1" : "0");
}