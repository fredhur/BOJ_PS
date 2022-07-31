#include <iostream>
#include <stack>
using namespace std;
int N;
int A[1000007];
struct Data
{
    int data;
    int idx;
    int ans;
};
stack<Data> stk;
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %d", &A[i]);
    }

    for (int i = N; i >= 1; i--)
    {
        if (stk.empty())
        {
            stk.push({A[i], i, -1});
        }
        else
        {
            const auto top = stk.top();
            stk.push({A[i], i, top.data == A[i] ? top.ans : top.idx});
        }
    }
    while (!stk.empty())
    {
        printf("%d ", stk.top().ans);
        stk.pop();
    }
}