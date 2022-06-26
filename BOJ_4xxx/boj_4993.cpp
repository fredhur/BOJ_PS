#include <iostream>
using namespace std;
char map[30][30];
int W, H;
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, 1, -1};
int initY, initX;
bool visited[30][30];
int ans;
void init()
{
    ans =0;
    for(int i=0; i<30; i++)
    {
        for(int j=0; j<30;j++)
        {
            visited[i][j] = 0;
        }
    }
}
void input()
{

    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            scanf(" %1c", &map[i][j]);
            if(map[i][j] == '@')
            {
                initY = i, initX = j;
            }
        }
    }
}
void dfs(int cy, int cx)
{

    for(int i=0; i<4; i++)
    {
        int ny = cy + diry[i];
        int nx = cx + dirx[i];

        if(0<=ny && ny < H && 0<= nx && nx < W && visited[ny][nx] ==false && map[ny][nx] != '#' && map[ny][nx] == '.' )
        {
            visited[ny][nx] = true;
            ans++;
            dfs(ny,nx);
        }
    }
}
int main()
{

    while (true)
    {
        scanf("%d %d", &W, &H);
        if (W == 0 && H == 0) break;
        input();
        init();
        dfs(initY, initX);
        printf("%d\n", ans + 1);
    }
}