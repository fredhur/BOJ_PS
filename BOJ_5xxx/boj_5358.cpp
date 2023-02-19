#include <cstdio>
#include <cctype>
char CapitalLut[256];
char LowerCaseLut[256];
void Init()
{

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        CapitalLut[ch] = ch;
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        LowerCaseLut[ch] = ch;
    }

    CapitalLut['I'] = 'E';
    CapitalLut['E'] = 'I';

    LowerCaseLut['i'] = 'e';
    LowerCaseLut['e'] = 'i';
}

int main()
{
    char str[300];
    Init();
    while (scanf("%[^\n]s", str) != EOF)
    {
        getchar();
        
        for (int i = 0; str[i]; i++)
        {
            if (isupper(str[i]))
            {
                str[i] = CapitalLut[str[i]];
            }
            else if(islower(str[i]))
            {
                str[i] = LowerCaseLut[str[i]];
            }
            
        }
        printf("%s\n", str);
        
    }
    return 0;
}