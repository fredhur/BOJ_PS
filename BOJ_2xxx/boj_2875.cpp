// Title : 대회 or 인턴 https://www.acmicpc.net/problem/2875
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K;
int main()
{
    
    scanf("%d %d %d", &N, &M, &K);

    for (int i = K; i > 0; i--)
    {
        if (N >= (M * 2))
        {
            N--;
        }
        else if (N < (M * 2))
        {
            M--;
        }
    }
    if ((N / 2) < M)
    {
        M = N / 2;
    }
    printf("%d", M);
}