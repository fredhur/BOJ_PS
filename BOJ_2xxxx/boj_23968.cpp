#include <iostream>
int N, K, A[10007];
template <typename T>
void Swap(T &a, T &b)
{
    T t = a;
    a = b, b = t;
}
void bubbleSort(int A[], int N)
{
    int cnt = 0;
    for (int i = N - 1; i >= 1; i--)
    {

        for (int j = 0; j <= i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                cnt++;
                Swap(A[j], A[j + 1]);
                if (cnt == K)
                {
                    printf("%d %d", A[j], A[j + 1]);
                    return;
                }
            }
        }
    }
    puts("-1");
}
int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &A[i]);
    }
    bubbleSort(A, N);
}