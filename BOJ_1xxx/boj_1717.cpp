// Title : 집합의 표현 https://www.acmicpc.net/problem/1717
#include <cstdio>
int n, m;
int parent[1'000'007];
void init()
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
    }
}
int findRoot(int x)
{
    if (x == parent[x])
    {
        return x;
    }

    return parent[x] = findRoot(parent[x]);
}
void Union(int x, int y)
{
    const auto rootX = findRoot(x);
    const auto rootY = findRoot(y);

    parent[rootY] = rootX;

}
int main()
{
    scanf("%d %d", &n, &m);
    init();
    for (int i = 0; i < m; i++)
    {
        int cmd;
        int a, b;
        scanf(" %d %d %d", &cmd, &a, &b);
        if (cmd == 0)
        {
            Union(a, b);
        }
        else
        {
            puts(findRoot(a) == findRoot(b) ? "YES" : "NO");
        }
    }
}