#include <cstdio>
template <typename T>
inline void Swap(T &a, T &b)
{
    T t= a;
    a = b, b=t;
    return;
}
int main()
{
    int arr[5];
    for(int i=0; i<5; i++)
    {
        scanf("%d", &arr[i]);
    }

    for(int cnt=0; cnt<5; cnt++)
    {
        for(int i=0; i<4; i++)
        {
            if(arr[i] > arr[i+1])
            {
                Swap(arr[i], arr[i+1]);
                for(int j=0; j<5; j++)
                {
                    printf("%d ", arr[j]);
                }puts("");
            }
        }
    }
    return 0;
}