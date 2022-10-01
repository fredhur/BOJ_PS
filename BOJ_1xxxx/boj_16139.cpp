#include <iostream>
#include <string>
using namespace std;
constexpr auto SIZE = (200'007);
using ll = int;
struct Data
{
	ll alphabetSum[26];
}pSum[SIZE];

string str;

void init()
{
	const auto idx = str[0] - 'a';

	for (int i = 0; i < 26; i++)
	{
		pSum[0].alphabetSum[i] = 0;
	}
	pSum[0].alphabetSum[idx] = 1;
}
int main()
{
	cin >> str;
	init();
	for (int i = 1; str[i]; i++)
	{
		const auto idx = str[i] - 'a';
		for (int j = 0; j < 26; j++)
		{

			pSum[i].alphabetSum[j] = pSum[i - 1].alphabetSum[j] + (j == idx);

		}
	}
	ll query;
	scanf(" %d", &query);

	while (query--)
	{
		char ch;
		int l, r;
		scanf(" %c %d %d", &ch, &l, &r);
		const auto idx = ch - 'a';
		printf("%d\n", pSum[r].alphabetSum[idx] - pSum[l].alphabetSum[idx] + (str[l] == ch));
	}

	return 0;
}