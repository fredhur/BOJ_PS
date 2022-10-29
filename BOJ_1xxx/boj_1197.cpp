// Title : 최소 스패닝 트리 https://www.acmicpc.net/problem/1197
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Data
{
    int start;
    int end;
    int value;
    bool operator<(const Data &rhs) const
    {
        return value < rhs.value;
    }
};
int V, E;
int parent[10007];
vector<Data> edges;
int findRoot(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findRoot(parent[x]);
}
void makeUnion(int x, int y)
{
    x = findRoot(x);
    y = findRoot(y);
    if (x != y)
        parent[y] = x;
}
vector<Data> ret;
int main()
{
    scanf("%d %d", &V, &E);
    for (int i = 0; i < E; i++)
    {
        Data d;
        scanf(" %d %d %d", &d.start, &d.end, &d.value);
        edges.push_back(d);
    }

    for (int i = 0; i <= V; i++)
    {
        parent[i] = i; // init union
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++)
    {
        const auto start = edges[i].start;
        const auto end = edges[i].end;
        if (findRoot(start) == findRoot(end))
            continue;

        ret.push_back(edges[i]);
        makeUnion(start, end);

        if (ret.size() == V - 1)
            break;
    }
    int sum = 0;
    for (auto &i : ret)
    {
        sum += i.value;
    }
    printf("%d\n", sum);
    return 0;
}