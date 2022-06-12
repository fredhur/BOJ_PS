#include <cstdio>

char map[55][55];
bool chk[55][55];
int N, M;
int ans;

bool chkValidPosition(int i, int j)
{
	if (i >= 0 && i < N && j >= 0 && j < M)
	{
		return true;
	}

	return false;
}
void dfs(int i, int j, char init)
{

	if (chk[i][j] == true || chkValidPosition(i, j) == false || map[i][j] != init)
	{
		return;
	}

	if (init == '|')
	{
		chk[i][j] = true;
		dfs(i - 1, j, init);
		dfs(i + 1, j, init);
		return;
	}

	else if (init == '-')
	{
		chk[i][j] = true;
		dfs(i, j + 1, init);
		dfs(i, j - 1, init);
		return;
	}
}
void initMap()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf(" %1c", &map[i][j]);
		}
	}
}
void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{

			if (chk[i][j] == false)
			{
				dfs(i, j, map[i][j]);
				ans++;
			}

		}
	}
}
int main()
{
	initMap();
	solve();
	printf("%d", ans);
}