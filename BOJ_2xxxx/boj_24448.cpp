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