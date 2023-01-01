#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int idx;
set<int, less<int>> s;
int CalcClockNumber(vector<char>& v)
{
	static constexpr int db[4][4] = {
		{0,1,2,3},
		{1,2,3,0},
		{2,3,0,1},
		{3,0,1,2}
	};
	int r = 0x7fffffff;
	for (int i = 0; i < 4; i++)
	{
		auto& l = db[i];

		int t = (v[l[0]] - '0') * 1000 + (v[l[1]] - '0') * 100 + (v[l[2]] - '0') * 10 + (v[l[3]] - '0');

		r = (r > t) ? t : r;
	}

	return r;
}


void InitDB()
{


	for (char i = '1'; i <= '9'; i++)
	{
		for (char j = '1'; j <= '9'; j++)
		{
			for (char k = '1'; k <= '9'; k++)
			{
				for (char l = '1'; l <= '9'; l++)
				{
					vector<char> c{ i, j,k, l };
					auto d = CalcClockNumber(c);
					s.insert(d);
				}
			}
		}
	}

}



int main()
{

	InitDB();
	vector<char> clockNum;
	for (int i = 0; i < 4; i++)
	{
		char num;
		cin >> num;
		clockNum.push_back(num);

	}

	auto d = CalcClockNumber(clockNum);


	int idx = 0;

	for (auto& i : s)
	{
		idx++;
		if (i == d)
		{
			printf("%d", idx);
			goto END;
		}
	}
END:

	return 0;
}