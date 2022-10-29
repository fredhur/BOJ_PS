// Title : 図書館 2 (Library 2) https://www.acmicpc.net/problem/24448
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int N;
stack<string> stk;
int main()
{
    cin >> N;
    for(int i=0; i<N; i++)
    {
        string in;
        cin >> in;
        if(in=="READ")
        {
            cout << stk.top() << '\n';
            stk.pop();
            
        }
        else 
        {
            stk.push(in);
        }
    }
    return 0;
}