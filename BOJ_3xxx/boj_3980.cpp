#include <cstdio>
#include <vector>
int s[11][11];
bool chk[11];
std::vector<int> v;
int score(std::vector<int> &v)
{
    int sum = 0;
    for (int i = 0; i < 11; i++)
    {
        sum += s[i][v[i]];
    }

    return sum;
}
int ans = 0;
void dfs(int player)
{

    if (v.size() == 11)
    {
        ans = std::max(ans, score(v));
        return;
    }

    for (int i = 0; i < 11; i++)
    {
        if (chk[i] == false && s[player][i] != 0)
        {
            chk[i] = true;
            v.push_back(i);
            dfs(player + 1);
            v.pop_back();
            chk[i] = 0;
        }
    }
}

int main()
{
    int tc;
    scanf("%d", &tc);

    while (tc--)
    {
        v.clear();
        ans = 0;
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                scanf(" %d", &s[i][j]);
            }
        }

        dfs(0);

        printf("%d\n", ans);
    }

    return 0;
}