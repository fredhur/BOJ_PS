#include <cstdio>
char map[102][102];
int main()
{
    int R, C;
    int A, B;
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            scanf(" %1c", &map[i][j]);
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            map[i][2 * C - 1 - j] = map[i][j];
        }
    }

    for (int i = 0; i < 2*C; i++)
    {
        for (int j = 0; j < R; j++)
        {
            map[2 * R - 1 - j][i] = map[j][i];
        }
    }

    scanf(" %d %d", &A, &B);
    A--, B--;
    map[A][B] = (map[A][B] == '#') ? '.' : '#';

    for(int i=0; i<2*R; i++)
    {
        for(int j=0; j<2*C; j++)
        {
            printf("%c", map[i][j]);
        }puts("");
    }

    return 0;
}