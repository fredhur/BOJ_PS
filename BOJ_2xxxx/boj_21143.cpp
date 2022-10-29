// Title : Magic Trick https://www.acmicpc.net/problem/21143
#include <cstdio>
int lut[26];
int main()
{
    char str[55];
    scanf("%s",str);
    bool flag = false;
    for(int i=0; str[i]; i++)
    {
        char ch = str[i];
        lut[ch-'a']++;
        if(lut[ch-'a'] == 2)
        {
            flag = true;
            break;
        }
    }
    puts(flag == true ? "0" : "1" );

    return 0;
}