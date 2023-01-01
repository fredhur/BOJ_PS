#include <cstdio>
using Int = int;
constexpr auto SIZE = 10'007;
struct Data
{
	Int teamId;
	Int finalScore;
	Int submitCount;
	Int submitTime;
	Int solvedProblem[102];
	void Init(const int &_teamId)
	{
		teamId = _teamId;
		finalScore = submitCount = submitTime = 0;

		for (int i = 0; i < 102; i++)
		{
			solvedProblem[i] = 0;
		}
	}
	void Update(const int& pIdx, const int &score)
	{
		
		if (solvedProblem[pIdx] < score)
		{
			if (solvedProblem[pIdx] == 0)
			{
				finalScore += score;
				solvedProblem[pIdx] = score;
			}
			else
			{
				finalScore -= solvedProblem[pIdx];
				solvedProblem[pIdx] = score;
				finalScore += score;
			}
		}

	}

	bool operator < (const Data& r) const
	{
		if (finalScore == r.finalScore)
		{
			if (submitCount == r.submitCount)
			{
				return submitTime > r.submitTime;
			}
			return submitCount > r.submitCount;
		}

		return finalScore < r.finalScore;
	}
	bool operator > (const Data& r) const
	{
		return !((*this) < r);
	}
	
}data[SIZE], tmp[SIZE];


template <typename T>
void Merge(T data[], int s, int m, int e)
{
	int i = s;
	int j = m + 1;
	int k = s;


	while (i <= m && j <= e)
	{
		if (data[i] > data[j])
		{
			tmp[k++] = data[i++];
		}
		else
		{
			tmp[k++] = data[j++];
		}
	}


	if (i <= m)
	{
		for (int l = i; l <= m; l++)
		{
			tmp[k++] = data[l];
		}
	}
	else
	{
		for (int l = j; l <= e; l++)
		{
			tmp[k++] = data[l];
		}
	}

	for (int i = s; i <= e; i++)
	{
		data[i] = tmp[i];
	}


}

template <typename T>
void MergeSort(T data[], int s, int e)
{
	if (s < e)
	{
		int m = (s + e) / 2;
		MergeSort(data, s, m);
		MergeSort(data, m + 1, e);
		Merge(data, s, m, e);
	}
}
int main()
{
	int tc;
	scanf("%d", &tc);

	while (tc--)
	{
		int n, k, t, m;
		scanf(" %d %d %d %d", &n, &k, &t, &m);

		for (int i = 1; i <= n; i++)
		{
			data[i].Init(i);
		}
		for (int submitTime = 0; submitTime < m; submitTime++)
		{
			int id, problemIdx, score;
			scanf(" %d %d %d", &id, &problemIdx, &score);
			data[id].Update(problemIdx, score);
			data[id].submitCount++;
			data[id].submitTime = submitTime;
		}

		MergeSort(data, 1, n);

		
		for (int i = 1; i <=n; i++)
		{
			if (data[i].teamId == t)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}