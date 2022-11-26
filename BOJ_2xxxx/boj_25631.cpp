// Title : 마트료시카 합치기 https://www.acmicpc.net/problem/25631
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int> pq;
int N;
int arr[1004];
int idx;
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int n;
        scanf(" %d", &n);
        pq.push(n);
    }
   
    
    while(!pq.empty())
    {
        int top = pq.top();
        pq.pop();

        bool flag = false;
        for(int i=0; i<=idx; i++)
        {
            if(arr[i] > top)
            {
                arr[i] = top;
                flag = true;
                break;
            }
        }
        if(flag == false)
        {
            idx++;
            arr[idx] = top;
        }
    }
    printf("%d\n", idx);
    return 0;
}