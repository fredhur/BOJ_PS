// Title : 달리기 https://www.acmicpc.net/problem/2517
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
// segment tree build up.
using ll = int;
constexpr auto NUMBER = 500007;
ll tree[NUMBER * 4];
ll arr[NUMBER];

int InitTree(int start, int end, int node)
{
    if (start == end)
    {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    return tree[node] = InitTree(start, mid, node * 2) + InitTree(mid + 1, end, node * 2 + 1);
}

int Sum(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }

    if (left <= start && end <= right)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;

    return Sum(start, mid, node * 2, left, right) + Sum(mid + 1, end, node * 2 + 1, left, right);
}

void Update(int start, int end, int node, int index, int diff)
{
    if (index < start || index > end)
    {
        return;
    }

    tree[node] += diff;

    if (start == end)
    {
        return;
    }
    int mid = (start + end) / 2;
    Update(start, mid, node * 2, index, diff);
    Update(mid + 1, end, node * 2 + 1, index, diff);
}
int N;
vector<int> v;
int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int n;
        scanf(" %d", &n);
        arr[i] = n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());


    for (auto i = 0; i < N; i++)
    {
        auto index = (lower_bound(v.begin(), v.end(), arr[i])) - v.begin();
        Update(0, N-1, 1, index, 1);
        printf("%d\n", i + 1 - Sum(0, N-1, 1, 0, index - 1));
    }
    return 0;
}
