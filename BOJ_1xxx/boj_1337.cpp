#include <cstdio>
constexpr auto SIZE = 100'007;
int arr[SIZE];
int tmp[SIZE];
void Merge(int arr[], int s, int m, int e)
{
	int i = s;
	int j = m + 1;
	int k = s;
	while (i <= m && j <= e)
	{
		if (arr[i] < arr[j])
		{
			tmp[k++] = arr[i++];
		}
		else
		{
			tmp[k++] = arr[j++];
		}
	}

	if (i <= m)
	{
		for (int t = i; t <= m; t++)
		{
			tmp[k++] = arr[t];
		}

	}
	else
	{
		for (int t = j; t <= e; t++)
		{
			tmp[k++] = arr[t];
		}
	}
	for (int i = s; i <= e; i++)
	{
		arr[i] = tmp[i];
	}

	return;
}

void MergeSort(int arr[], int s, int e)
{
	if (s < e)
	{
		int m = (s + e) / 2;
		MergeSort(arr, s, m);
		MergeSort(arr, m + 1, e);
		Merge(arr, s, m, e);
	}

}


template<typename T>
T ABS(T a)
{
	return a < 0 ? -a : a;
}

template <typename T>
T Max(T a, T b)
{
	return a < b ? b : a;
}
int N, M;
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf(" %d", &arr[i]);
	}
	MergeSort(arr, 0, N - 1);

	// 차이가 5에 가장 가까운 idx 2개.
	M = 4;
	int start = 0;
	int sidx = 0, eidx = 1;
	
	
	int cnt = 0, ans = 0;
	for (int end = 0; end < N; end++)
	{
		cnt++;

		while (arr[end] - arr[start] > 4)
		{
			start++;
			cnt--;
		}
		ans = Max(ans, cnt);
	}

	if (ans > 5)
	{
		ans = 5;
	}
	printf("%d", 5 - ans);
}