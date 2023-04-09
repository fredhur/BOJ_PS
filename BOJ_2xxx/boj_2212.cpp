#include <cstdio>
constexpr auto SIZE = 10'007;
int arr[SIZE];
int dist[SIZE];
int tmp[SIZE];
void Merge(int arr[], int s, int m, int e)
{
    int i=s;
    int j=m+1;
    int k=s;
    while(i<=m && j<=e)
    {
        if(arr[i] <=arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else 
        {
            tmp[k++] = arr[j++];
        }
    }

    if(i<=m)
    {
        for(int t=i; t<=m; t++)
        {
            tmp[k++] = arr[t];
        }
    }else{
        for(int t=j; t<=e; t++)
        {
            tmp[k++] = arr[t];
        }
    }
    for(int i=s; i<=e; i++)
    {
        arr[i] = tmp[i];
    }
}
void MergeSort(int data[], int s, int e)
{
    if(s<e)
    {
        int mid = (s+e)/2;
        MergeSort(data, s, mid);
        MergeSort(data, mid+1,e);
        Merge(data, s, mid, e);
    }
}
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);

    for(int i=0; i<N; i++)
    {
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, N-1);
    int i=0;
   
    for(int j=1; j<N; j++)
    {
        if(arr[i] != arr[j])
        {
            i++;
            arr[i]= arr[j];
        }
    }


    int size = i+1;
    
    
    int idx=0;
    for(int i=size-1; i >= 1; i--)
    {
        dist[idx++]= arr[i] - arr[i-1];
    }

     MergeSort(dist, 0, idx-1);
     int totSum =0;
     for(int i=0; i< idx; i++)
     {
        totSum += dist[i];
     }
     int partialSum =0;
     for(int i=idx-1; i>= idx-K + 1; i--)
     {
        partialSum += dist[i];
     }
     printf("%d", totSum-partialSum);
   
    return 0;
}