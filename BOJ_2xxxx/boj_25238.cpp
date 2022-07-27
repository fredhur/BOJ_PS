#include <cstdio>
int a, b;
int main()
{
    scanf("%d %d", &a, &b);
    auto ret = a * (100 - b) / 100.0f;
    puts(ret < 100.0f ? "1" : "0");
}