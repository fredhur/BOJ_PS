#include <cstdio>
const char *str[2] = {"Naver Whale", "Naver D2"};
int main()
{
    char ch;
    scanf("%c", &ch);
    const bool isN = (ch == 'N' || ch == 'n');
    printf("%s\n", str[isN]);
}