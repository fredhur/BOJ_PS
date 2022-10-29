// Title : 複雑な文字列 (Complex String) https://www.acmicpc.net/problem/24080
#include <cstdio>
int N, cnt[26];
int main()
{
 
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        char ch;
        scanf(" %c", &ch);
        cnt[ch-'A'] =1;
    }
    int sum = 0;
    for(int i=0; i<26; i++)
    {
        sum += cnt[i];
    }
    puts(sum >= 3 ? "Yes":"No");
}