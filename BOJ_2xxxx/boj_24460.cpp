// Title : 특별상이라도 받고 싶어 https://www.acmicpc.net/problem/24460
#include <iostream>
#include <algorithm>
#include <vector>
int N;
int arr[1025][1025];
inline int pickSecondLeast(int a, int b, int c, int d)
{
    int arr[] = {a, b, c, d};
    std::sort(arr, arr + 4);

    return arr[1];
}
int sol(int y, int x, int size)
{

    if (size == 2)
    {
        return pickSecondLeast(arr[y][x], arr[y - 1][x], arr[y][x - 1], arr[y - 1][x - 1]);
    }

    const auto a = sol(y - (size >> 1), x - (size >> 1), (size >> 1));

    const auto b = sol(y - (size >> 1), x, (size >> 1));

    const auto c = sol(y, x - (size >> 1), (size >> 1));

    const auto d = sol(y, x, (size >> 1));

    return pickSecondLeast(a, b, c, d);
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %d", &arr[i][j]);
        }
    }
    if (N == 1)
    {
        printf("%d\n", arr[0][0]);
    }
    else
    {
        printf("%d\n", sol(N - 1, N - 1, N));
    }
}