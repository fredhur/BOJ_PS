#include <iostream>
#include <algorithm>
int A[1000007];
int B[1000007];
using ll = long long;

int findClosest(int arr[], int target, int len)
{
    int low = 0; int high = len -1;
    int ret = 0;
    bool find = false;
    int diff = 0x7fffffff;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(std::abs(arr[mid] - target) < abs(diff))
        {
            ret = arr[mid];
            diff = target-arr[mid];
        }
        else if(std::abs(arr[mid] - target) == abs(diff) && arr[mid] < target)
        {
            ret = arr[mid];
        }
        if(target-arr[mid] == 0 ) break;

        if(target-arr[mid] >0 ) 
        {
            low = mid+1;
        }
        else if(target-arr[mid] <0 )
        {
            high = mid-1;
        } 
    }
    
    return ret;
}

int main()
{
    int tc;
    scanf("%d", &tc);
    while(tc--)
    {
        int n, m;
        scanf(" %d %d", &n, &m);
        for(int i=0; i<n; i++)
        {
            scanf(" %d", &A[i]);
        }
        for(int i=0; i<m; i++)
        {
            scanf(" %d", &B[i]);
        }
        std::sort(B,B+m);
        ll sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += findClosest(B, A[i], m);
        }
        printf("%lld\n", sum);
    }
        
        
    return 0;
}