#include <iostream>
#include <string>
using namespace std;
constexpr auto INF = 999;

bool visited[101];
string s;
void dfs(int left, int right) {
	int chk = INF, idx = -1;
	for (int i = left; i < right + 1; i++) 
	{
		if (!visited[i] && chk > s[i]) 
		{
			chk = s[i];
			idx = i;
		}
	}
	if (chk == INF) return;
	visited[idx] = true;
	for (int i = 0; s[i]; i++) 
	{
		if (visited[i]) cout << s[i];
	}
	cout << '\n';
	dfs(idx + 1, right);
	dfs(left, idx - 1);
}
int main() {

	cin >> s;
	dfs(0, s.size() - 1);
}