#include <cstdio>
int main()
{
    int N;
    scanf("%d", &N);

    int midlen = 3;
    int curlen = 3;
   
    while (curlen < N)
    {
        midlen++;
        curlen = curlen * 2 + midlen;
    }
    //printf("it is n : %d, curLen : %d , midLen : %d", n, curlen, midlen);

    while (true)
    {
        int prevlen = (curlen - midlen) / 2;

        if (N <= prevlen)
        {
            midlen--;
            curlen = prevlen;
        }
        else if (N > midlen + prevlen)
        {
            N = N - (prevlen + midlen);
            midlen--;
            curlen = prevlen;
        }
        else // 가운데에 속할 경우.
        {
            N = N - prevlen;
            break;
        }
    }

    if(N==1)
    {
        puts("m");
    }
    else 
    {
        puts("o");
    }
    return 0;
}