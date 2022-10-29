// Title : 숫자 정사각형 https://www.acmicpc.net/problem/1051
#include <cstdio>

template <typename T>
T MIN(T &a, T &b)
{
    return a > b ? b : a;
}
int N, M;

bool checkMap(int (&map)[55][55], int len)
{

    for (int i = 0;  i+len-1 < N; i++)
    {
        for (int j = 0;  j+len-1 <M; j++)
        {
            auto leftTop = map[i][j];
            auto rightTop = map[i][j + len-1];
            auto leftBottom = map[i + len-1][j];
            auto rightBottom = map[i + len-1][j + len-1];
            if (leftTop == rightTop && rightTop == leftBottom && leftBottom == rightBottom)
            {
                return true;
            }
        }
    }
    return false;
}

int solve(int (&map)[55][55])
{
    auto maxLen = MIN(N, M);

    for (auto i = maxLen; i >= 1; i--)
    {
        if(checkMap(map, i))
        {
            return i*i;
        }
    }
    return 1;
}
void input(int (&map)[55][55])
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf(" %1d", &map[i][j]);
        }
    }
}
int main()
{
    int map[55][55];
    input(map);
    printf("%d",solve(map));
}