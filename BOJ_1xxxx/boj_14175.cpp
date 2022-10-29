// Title : The Cow-Signal https://www.acmicpc.net/problem/14175
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    for(int i=0; i<M; i++)
    {
        string str;
        for(int j=0; j<N; j++)
        {
            char ch;
            scanf(" %1c", &ch);
            for(int k=0; k<K; k++) str+= ch;
        }
        for(int k=0; k<K; k++) cout << str << '\n';
    }
}