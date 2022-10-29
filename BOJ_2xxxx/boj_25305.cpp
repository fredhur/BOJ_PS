// Title : 커트라인 https://www.acmicpc.net/problem/25305
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> members;

int N,K;
int main()
{
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++)
    {
        int m;
        scanf(" %d", &m);
        members.push_back(m);
    }
    std::sort(members.begin(), members.end(),greater<int>());
    printf("%d", members[K-1]);
}
