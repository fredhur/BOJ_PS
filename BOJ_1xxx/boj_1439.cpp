#include <cstdio>
enum TOKEN
{
	ORG,
	ZERO,
	ONE,
	SIZE
};

inline int strlen(char* s)
{
	int i;
	for (i = 0; s[i]; i++);
	return i;
}
int countToken(char* s, const int& len)
{
	int idx = 0;
	int cnt = 0;
	
	while (idx < len)
	{
		const int length = strlen(&s[idx]);
		cnt += (length >0);
		idx += length +1;
	}
	return cnt;
}

char arr[SIZE][1000007];

template <typename T>
T MyMin(T& a, T& b)
{
	return a > b ? b : a;
}

int main()
{

	scanf("%s", arr[ORG]);
	const auto len = strlen(arr[ORG]);
	for (int i = 0; i < len; i++)
	{
		if (arr[ORG][i] == '1')
		{
			arr[ZERO][i] = '\0';
		}
		else
		{
			arr[ZERO][i] = arr[ORG][i];
		}

		if (arr[ORG][i] == '0')
		{
			arr[ONE][i] = '\0';
		}
		else
		{
			arr[ONE][i] = arr[ORG][i];
		}
	}

	const int oneToken = countToken(arr[ONE], len);
	const int zeroToken = countToken(arr[ZERO], len);
	printf("%d", MyMin(oneToken, zeroToken));


	return 0;
}