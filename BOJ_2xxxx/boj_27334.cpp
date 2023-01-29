#include <cstdio>
int person[105];
int rank[105];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		rank[i] = 1;
		scanf(" %d", &person[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (person[i] > person[j]) rank[i]++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%d ", rank[i]);
	}

	return 0;
}