// Title : DNA 해독 https://www.acmicpc.net/problem/1672
#include <cstdio>
#include <stack>
using namespace std;

inline int CvtDNA(const char ch)
{
    if(ch == 'A')
    {
        return 0;
    }
    else if(ch=='G')
    {
        return 1;
    }
    else if(ch == 'C')
    {
        return 2;
    }
    else 
    {
        return 3;
    }
}


char lut[4][4] ={

    'A','C','A','G',
    'C','G','T','A',
    'A','T','C','G',
    'G','A','G','T'
};
int N;
stack<char> stk;
int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        char ch;
        scanf(" %1c", &ch);
        stk.push(ch);
    }

    while(stk.size() != 1)
    {
        const char col = CvtDNA(stk.top()); 
        stk.pop();
        const char row = CvtDNA(stk.top());
        stk.pop();
        const char newDNA = lut[row][col];
        stk.push(newDNA); 
        
    }
    printf("%c\n", stk.top());
    return 0;
}
