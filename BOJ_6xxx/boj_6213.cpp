#include <cstdio>
constexpr auto SIZE = 50'005;
constexpr auto INT_MAX = 0x7fffffff;
struct Data
{
    int min;
    int max;
};
int arr[SIZE];
Data tree[SIZE * 4];

template <typename T>
inline T MAX(T A, T B)
{
    return A > B ? A : B;
}

template <typename T>
inline T MIN(T A, T B)
{
    return A < B ? A : B;
}

Data InitTree(int node, int s, int e)
{

    if (s == e)
    {
        tree[node] = {arr[s], arr[s]};
        return tree[node];
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (s + e) / 2;
    InitTree(left, s, mid);
    InitTree(right, mid + 1, e);

    return tree[node] = {MIN(tree[left].min, tree[right].min), MAX(tree[left].max, tree[right].max)};
}

Data query(int node, int qs, int qe, int s, int e)
{

    if (qs <= s && e <= qe)
    {
        return tree[node];
    }

    if (qs > e || qe < s)
    {
        return Data{INT_MAX, -1};
    }

    int left = node * 2;
    int right = node * 2 + 1;

    int mid = (s + e) / 2;

    Data leftTree = query(left, qs, qe, s, mid);
    Data rightTree = query(right, qs, qe, mid + 1, e);

    return Data{MIN(leftTree.min, rightTree.min), MAX(leftTree.max, rightTree.max)};
}

int main()
{
    int N, Q;
    scanf("%d %d", &N, &Q);

    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &arr[i]);
    }
    InitTree(1, 1, N);

    while (Q--)
    {
        int qs, qe;
        scanf(" %d %d", &qs, &qe);
        Data ret = query(1, qs, qe, 1, N);
        printf("%d\n", ret.max - ret.min);
    }

    return 0;
}