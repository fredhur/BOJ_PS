// Title : 암호 https://www.acmicpc.net/problem/1718
#include <cstdio>
char str[30007];
char key[30007];
char convert(char ch, char key)
{
  
    int delta = ch -key -1;
   
    if(delta < 0)
    {
        return 'z' + delta + 1 ;
    }
    else 
    {
        return delta + 'a';
    }
   
}
int strlength(char str[])
{
    int i=0;
    for(i=0; str[i]; i++);
    return i;
}
int main()
{
    scanf("%[^\n]", str);
    scanf(" %s", key);
    const int keylen = strlength(key);
    int j=0;
    for(int i=0; str[i]; i++)
    {   
        if(str[i] == ' ')
        {
            j++;
            j = j%(keylen);
            printf(" ");
            continue;
        }

        printf("%c", convert(str[i], key[j++]));
        j = j%keylen;
    }
    puts("");
    return 0;
}