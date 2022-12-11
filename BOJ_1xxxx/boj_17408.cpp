#include <iostream>
#include <algorithm>
constexpr auto SIZE = 100'004;
struct Data
{
    int num1;
    int num2;
};
int arr[SIZE];
Data tree[SIZE * 4];
// 구간별 상위 2개를 tree 에 항상 저장해둔다.
Data InitTree(int node, int start, int end)
{

    if (start == end)
    {
        tree[node].num1 = arr[start];
        tree[node].num2 = -1;

        return tree[node];
    }
    int mid = (start + end) / 2;

    const Data &leftTree = InitTree(node * 2, start, mid);

    const Data &rightTree = InitTree(node * 2 + 1, mid + 1, end);

    int tmp[4] = {leftTree.num1, leftTree.num2, rightTree.num1, rightTree.num2};

    std::sort(tmp, tmp + std::size(tmp));

    tree[node].num1 = tmp[3];
    tree[node].num2 = tmp[2];

    return tree[node];
}

void UpdateTree(int node, int start, int end, int idx, int updateNum)
{
    if (idx < start || end < idx)
    {
        return;
    }

    if (start == end)
    {
        tree[node].num1 = updateNum;
        tree[node].num2 = -1;
        return;
    }

    int mid = (start + end) / 2;
    UpdateTree(node * 2, start, mid, idx, updateNum);
    UpdateTree(node * 2 + 1, mid + 1, end, idx, updateNum);

    auto &left = tree[node * 2];
    auto &right = tree[node * 2 + 1];

    int tmp[4] = {left.num1, left.num2, right.num1, right.num2};

    std::sort(tmp, tmp + 4);

    tree[node].num1 = tmp[3];
    tree[node].num2 = tmp[2];

    return;
}
Data querySum(int node, int start, int end, int qL, int qR)
{
    if (end < qL || start > qR)
    {
        return {-1, -1};
    }

    if (qL <= start && end <= qR)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;

    const auto &left = querySum(node * 2, start, mid, qL, qR);
    const auto &right = querySum(node * 2 + 1, mid + 1, end, qL, qR);

    int tmp[4] = {left.num1, left.num2, right.num1, right.num2};
    std::sort(tmp, tmp + 4);
    return {tmp[3], tmp[2]};
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }
    InitTree(1, 0, N - 1);

    int tc;
    scanf(" %d", &tc);

    while (tc--)
    {
        int a;
        scanf(" %d", &a);

        if (a == 1)
        {
            int i, v;
            scanf(" %d %d", &i, &v);
            UpdateTree(1, 0, N - 1, i - 1, v);
        }
        else
        {
            int l, r;
            scanf(" %d %d", &l, &r);
            auto t = querySum(1, 0, N - 1, l - 1, r - 1);

            printf("%d\n", t.num1 + t.num2);
        }
    }
    return 0;
}