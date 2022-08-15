#include <cstdio>
int main()
{
    char str[200];
    scanf("%s", str);
    auto lambda = [](const char *s){int i=0; for(i=0; s[i]; i++); return i;};
    for(int i=lambda(str)-1; i>=0; i--)
    {
        printf("%c", str[i]);
    }puts("");
}