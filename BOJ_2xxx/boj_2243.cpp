#include <cstdio>
// By using setment tree, get the rank of some datas
using ll = long long;
constexpr auto SIZE = (1000005);
constexpr auto TREE_SIZE = SIZE * 4;
int arr[SIZE];
ll segmentTree[TREE_SIZE];
ll InitTree(int start, int end, int node)
{
    if (start == end)
    {
        return segmentTree[node] = arr[start];
    }
    int mid = (start + end) / 2;

    return segmentTree[node] = InitTree(start, mid, node * 2) + InitTree(mid + 1, end, node * 2 + 1);
}
int QueryToSegmentTree(int start, int end, int node, int left, int right)
{
    if (left < start || end > right)
        return 0;

    if (left <= start && end <= right)
    {
        return segmentTree[node];
    }

    int mid = (start + end) / 2;

    return QueryToSegmentTree(start, mid, node * 2, left, right) + QueryToSegmentTree(mid + 1, end, node * 2, left, right);
}
void UpdateTree(int start, int end, int node, int index, int diffVal)
{
    if (index < start || end < index)
        return;

    segmentTree[node] += diffVal; // 모든 구간합 갱신

    if (start == end)
        return;

    int mid = (start + end) / 2;
    UpdateTree(start, mid, node * 2, index, diffVal);

    UpdateTree(mid + 1, end, node * 2 + 1, index, diffVal);
}

int QuertyToGetRank(int start , int end, int node , int left, int right, int rank)
{
    if(start == end ) return start; // index 를 리턴 해준다. 

    int mid = ( start + end ) / 2;

    if(rank <= segmentTree[node*2])
    {
        return QuertyToGetRank(start, mid, node *2, left, right, rank);
    }
    else 
    {
        return QuertyToGetRank(mid+1, end, node*2+1, left, right, rank-segmentTree[node*2]);
    }   
    
}
int A, B, C;
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf(" %d", &A);
        if (A == 1)
        {
            scanf(" %d", &B);
            int idx = QuertyToGetRank(0, SIZE -1 , 1, 0, 0 , B);

            UpdateTree(0, SIZE-1, 1, idx, -1);
            printf("%d\n", idx);
        }
        else if (A == 2)
        {
            scanf(" %d", &B);
            scanf(" %d", &C);
            
            UpdateTree(0, SIZE-1, 1, B, C);
            
        }
    }
    return 0;
}