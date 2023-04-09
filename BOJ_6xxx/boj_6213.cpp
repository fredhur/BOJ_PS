#include <cstdio>
constexpr auto SIZE = 500'007;
using ll = long long;
struct Data
{
    int idx;
    int val;
};
Data arr[SIZE];
Data tmp[SIZE];

ll tree[4 * SIZE];

int InitTree(int node, int s, int e)
{
    if (s == e)
    {
        tree[node] = 1;
        return tree[node];
    }

    int left = node * 2;
    int right = left + 1;

    int mid = (s + e) / 2;
    tree[node] = InitTree(left, s, mid) + InitTree(right, mid + 1, e);

    return tree[node];
}

void updateTree(int node, int s, int e, int idx, int val)
{
    if (idx < s || idx > e)
    {
        return;
    }
    tree[node] += val;
    if (s == e)
    {
        return;
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (s + e) / 2;
    updateTree(left, s, mid, idx, val);

    updateTree(right, mid + 1, e, idx, val);
}

int query(int node, int qs, int qe, int s, int e)
{

    if (qe < s || e < qs)
    {
        return 0;
    }

    if (qs <= s && e <= qe)
    {
        return tree[node];
    }

    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (s + e) / 2;
    return query(left, qs, qe, s, mid) + query(right, qs, qe, mid + 1, e);
}

void Merge(Data arr[], int s, int m, int e)
{
    int i = s;
    int j = m + 1;
    int k = s;

    while (i <= m && j <= e)
    {
        if (arr[i].val <= arr[j].val)
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
        }
    }

    if (i <= m)
    {
        for (int t = i; t <= m; t++)
        {
            tmp[k++] = arr[t];
        }
    }
    else
    {
        for (int t = j; t<= e; t++)
        {
            tmp[k++] = arr[t];
        }
    }
    for (int i = s; i <= e; i++)
    {
        arr[i] = tmp[i];
    }
}
void MergeSort(Data arr[], int s, int e)
{
    if (s < e)
    {
        int m = (s + e) / 2;
        MergeSort(arr, s, m);
        MergeSort(arr, m + 1, e);
        Merge(arr, s, m, e);
    }
}
int main()
{
    // 주어진 배열에서 오른쪽으로 봤을때 자기보다 작은 수의 갯수를 카운팅하는 문제.
    // [4,5,1,2,6] 이라면
    // 4: 2 개 , 5 : 2 개 1 : 0개  2 : 0 개 6 : 0개
    // 이렇게 됌. 버블소트가 어차피 비교했을떄 비교 성공되면 swap이니깐.
    // 내림차순으로 6, 5, 4, 3, 2, 1 이렇게 세그먼트 트리에 넣는다.
    // 큰거부터 집어넣으면서 업데이트 및 갯수 세기. 큰거부터 하면 보장되니깐.
    // 자세한건 코드로... 줄세우기 랑 비슷함

    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &arr[i].val);
        arr[i].idx = i;
    }
    MergeSort(arr, 1, N);
   
    ll ans = 0; // answer is more than int
   
    InitTree(1, 1, N);
  
    for (int i = N; i >= 1; i--)
    {
        updateTree(1, 1, N, arr[i].idx, -1);

        ans += query(1, arr[i].idx + 1, N, 1, N);
     
    }
    printf("%lld", ans);

    return 0;
}