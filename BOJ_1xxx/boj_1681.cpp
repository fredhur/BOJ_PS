#include <cstdio>

int Solve(int N, int L)
{
    auto Analyzing = [](int num, const int L){
        while(num >0)
        {
            const int n = num %10;
            num = num /10;
            if(n==L) return false;
        }
        return true;
    };
    int cnt = 0;
    for(int i=1; ; i++)
    {
        cnt +=Analyzing(i, L);
        if(cnt == N)
        {
            return i;
        }
    }
    return 0;
}
int main()
{
    int N,L;
    scanf("%d %d", &N, &L);

    printf("%d\n", Solve(N, L));
    return 0;
}