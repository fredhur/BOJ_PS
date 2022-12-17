// Title : Intercepting Information https://www.acmicpc.net/problem/26209
#include <cstdio>
int main()
{
    int sum =0;
    for(auto i=0; i<8; i++)
    {
        int bit;
        scanf("%d", &bit);
        sum += bit;
    }
    puts(sum > 8 ? "F" : "S");
}