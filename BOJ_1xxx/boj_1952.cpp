#include <cstdio>
bool arr[102][102];
int M, N;
int diry[] = { 0, 1, 0, -1 };
int dirx[] = { 1, 0,-1,  0 };
int main()
{
	scanf("%d %d", &M, &N);
	int sy = 0, sx = 0;
	int dir = 0, ans = 0;
	while (true)
	{
		arr[sy][sx] = true;

		sy += diry[dir];
		sx += dirx[dir];

		if ((sy < 0 || sx < 0 || sx >= N || sy >= M) || (arr[sy][sx] == true))
		{
			sy -= diry[dir];
			sx -= dirx[dir];

			dir = (dir + 1) % 4;
			sy += diry[dir];
			sx += dirx[dir];
			ans++;
		}

		if (arr[sy][sx] == true) break;
	}
	printf("%d", ans - 1);



	return 0;
}