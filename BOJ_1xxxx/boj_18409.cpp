#include <cstdio>

bool isVowel(char ch)
{
    static const char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    for (int i = 0; i < 5; i++)
    {
        if (vowels[i] == ch)
            return true;
    }
    return false;
}
int main()
{
    int N;
    char str[55];
    scanf("%d %s", &N, str);
    int sum = 0;
    for (int i = 0; str[i]; i++)
    {
        sum += isVowel(str[i]);
    }
    printf("%d\n", sum);
}