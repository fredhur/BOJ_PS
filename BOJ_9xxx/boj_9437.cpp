#include <cstdio>
int main()
{

	while (true)
	{
		int N, P;
		scanf("%d", &N);

		if (N == 0) break;

		scanf(" %d", &P);

		if (P % 2 == 0)
		{
			if (P <= N / 2)
			{
				printf("%d %d %d\n", P - 1, N + 1 - P, N + 2 - P);
			}
			else
			{
				printf("%d %d %d\n", N + 1 - P, N + 2 - P, P - 1);
			}
		}
		else
		{
			if (P <= N / 2)
			{
				printf("%d %d %d\n", P + 1, N - P, N + 1 - P);
			}
			else
			{
				printf("%d %d %d\n", N - P, N + 1 - P, P + 1);
			}
		}
	}


	return 0;
}