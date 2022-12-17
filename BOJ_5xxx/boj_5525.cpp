// Title : IOIOI https://www.acmicpc.net/problem/5525
#include <cstdio>
constexpr auto LEN = 1'000'007;
char str[LEN];
int N, M;

int main()
{
    scanf("%d", &N);
    scanf(" %d", &M);
    scanf(" %s", str);
    int ans = 0;
    for (int i = 0; i < M; i++)
    {
        int k=0;
        if (str[i] == 'I')
        {
            
            while (str[i + 1] == 'O' && str[i + 2] == 'I')
            {
                k++;
                if (k == N)
                {
                    ans++;
                    k--;
                }
                i+=2;
            }
            k=0;

        }
    }
    printf("%d\n", ans);
    return 0;
}