#include <cstdio>
constexpr auto SIZE = 500'003;
int cnt[SIZE];
int arr[SIZE];
int sortedArr[SIZE];
int N;
void CountingSort(int arr[], int size)
{
    int j=0;
    for (int i = 0; i <SIZE; i++)
    {
        while (cnt[i]--)
        {
            sortedArr[j++] = i;
        }
    }
}
template <typename T>
inline T ABS(T N)
{
    return N > 0 ? N : -N;
}
int main()
{
  
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %d", &arr[i]);
        cnt[arr[i]]++;
    }

    CountingSort(arr, N);
   
    long long sum =0;
    for (int i = 0; i < N; i++) sum += ABS(sortedArr[i]-(i+1));
    
    printf("%lld", sum);
}