#include <iostream>
#include <queue>
using namespace std;


struct Scv
{
	int scv1;
	int scv2;
	int scv3;
	int cnt;
	
	bool isDeadAll()
	{
		return scv1 <= 0 && scv2 <= 0 && scv3 <= 0;
	}

	void Init(const int &_scv1, const int &_scv2, const int &_scv3, const int &_cnt)
	{
		scv1 = _scv1 < 0 ? 0 : _scv1;
		scv2 = _scv2 < 0 ? 0 : _scv2;
		scv3 = _scv3 < 0 ? 0 : _scv3;
		cnt = _cnt;
	}
};

queue<Scv> q;

bool visited[61][61][61];

int bfs(int (&init)[3])
{
	Scv scv{ init[0], init[1], init[2],0 };

	q.push(scv);
	while (!q.empty())
	{
		auto& frontScv = q.front();
		q.pop();
		auto cnt = frontScv.cnt;

		if (frontScv.isDeadAll())
		{
			return cnt;
		}
		if (visited[frontScv.scv1][frontScv.scv2][frontScv.scv3] == false)
		{
			visited[frontScv.scv1][frontScv.scv2][frontScv.scv3] = true;
			Scv scv0{};
			Scv scv1{};
			Scv scv2{};
			Scv scv3{};
			Scv scv4{};
			Scv scv5{};
			scv0.Init(frontScv.scv1 - 9, frontScv.scv2 - 3, frontScv.scv3 - 1, cnt + 1);
			scv1.Init(frontScv.scv1 - 9, frontScv.scv3 - 3, frontScv.scv2 - 1, cnt + 1);
			scv2.Init(frontScv.scv2 - 9, frontScv.scv1 - 3, frontScv.scv3 - 1, cnt + 1);
			scv3.Init(frontScv.scv2 - 9, frontScv.scv3 - 3, frontScv.scv1 - 1, cnt + 1);
			scv4.Init(frontScv.scv3 - 9, frontScv.scv1 - 3, frontScv.scv2 - 1, cnt + 1);
			scv5.Init(frontScv.scv3 - 9, frontScv.scv2 - 3, frontScv.scv1 - 1, cnt + 1);
			q.push(scv0);
			q.push(scv1);
			q.push(scv2);
			q.push(scv3);
			q.push(scv4);
			q.push(scv5);
		}
	}
	return -1;
}

int main()
{

	int N;
	int scv[3] = { 0,0,0 };
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> scv[i];
	}

	
	cout << bfs(scv);
}