#include <cstdio>

int A[10005];
int N, K;
int insertionSort(int A[])
{
	int cnt = 0;

	for (int i = 2; i <= N; i++)
	{
		int j = i - 1;
		int key = A[i];
		while (j >= 1 && key< A[j])
		{
			A[j + 1] = A[j];
			cnt++;
			if (cnt  == K)
			{
				return A[j + 1];
			}
	
			j--;
		}
		if (j + 1 != i)
		{
			A[j + 1] = key;
			cnt++;
			if (cnt  == K)
			{
				return A[j + 1];
			}
		}

	}

	return -1;
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++)
	{
		scanf(" %d", &A[i]);
	}
	
	const auto ans  = insertionSort(A);


	if (ans == -1)
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= N; i++)
	{
		printf("%d ", A[i]);
	}puts("");
	return 0;
}