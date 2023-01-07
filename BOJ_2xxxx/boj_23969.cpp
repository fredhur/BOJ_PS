#include <iostream>
int N, K;
int A[10007];
int bubbleSort(int A[])
{
	int cnt = 0;
	for (int i = N; i >= 2; i--)
	{
		for (int i = 1; i <= N - 1; i++)
		{
			if (A[i] > A[i + 1])
			{
				cnt++;
				std::swap(A[i], A[i + 1]);
				if (cnt == K)
				{
				
					return 0;
				}
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
	auto ret = bubbleSort(A);

	if(ret == -1)
	{
		puts("-1");
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			printf("%d ", A[i]);
		}puts("");
	}
	return 0;
}