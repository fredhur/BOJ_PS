#include <cstdio>

template <typename T>
void Swap(T &a, T &b)
{
    T t = a;
    a = b, b = t;
}
int main()
{
    int N, M;
    int arr[102];
    
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }
    while (M--)
    {
        int i, j, k;
        scanf(" %d %d %d", &i, &j, &k);

        int tmp[102];
        int sidx=0;
        for(int t=k; t<=j; t++)
        {
            tmp[sidx++] = arr[t];
        }

        for(int t=i; t<k; t++)
        {
            tmp[sidx++] = arr[t];
        }
        int s =i;
        for(int t=0; t<sidx; t++)
        {   
            arr[s++] = tmp[t];
        }

    }
    for(int i=1; i<=N; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}