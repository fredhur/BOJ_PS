// Title : Red and Black https://www.acmicpc.net/problem/4993
#include <iostream>
using namespace std;

class Solve
{
public:
    Solve() = default;
    ~Solve() = default;
    bool InitInput()
    {
        scanf("%d %d", &W, &H);
        if (W == 0 && H == 0) return false;
            
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                scanf(" %1c", &map[i][j]);
                if (map[i][j] == '@')
                {
                    initY = i, initX = j;
                }
            }
        }
        return true;
    }
    void init()
    {
        ans = 0;
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                visited[i][j] = 0;
            }
        }
    }

    void Dfs()
    {
        dfs(initY, initX);
    }
    void dfs(int cy, int cx)
    {

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + diry[i];
            int nx = cx + dirx[i];

            if (0 <= ny && ny < H && 0 <= nx && nx < W && visited[ny][nx] == false && map[ny][nx] != '#' && map[ny][nx] == '.')
            {
                visited[ny][nx] = true;
                ans++;
                dfs(ny, nx);
            }
        }
    }
    int GetAns() const 
    {
        return ans;
    }
private:
    int W, H, ans;
    int dirx[4] = {1, -1, 0, 0};
    int diry[4] = {0, 0, 1, -1};
    int initY, initX;
    char map[30][30];
    bool visited[30][30];
}solve;

int main()
{

    while (solve.InitInput())
    {
      
        solve.init();
        solve.Dfs();
       
        printf("%d\n", solve.GetAns()+1);
    }
}