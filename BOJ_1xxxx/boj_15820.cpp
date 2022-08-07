#include <iostream>
using namespace std;
int S1,S2;
int main()
{
    bool sampleTest = true;
    bool systemTest = true;
    scanf("%d %d", &S1, &S2);
    for(int i=0; i<S1; i++)
    {
        int userAns, ans;
        scanf("%d %d", &userAns, &ans);
        if(userAns != ans)
        {
            sampleTest = false;
        }
    }
    for(int i=0; i<S2; i++)
    {
        int userAns, ans;
        scanf("%d %d", &userAns, &ans);
        if(userAns != ans)
        {
            systemTest = false;
        }
    }

    if(sampleTest == false)
    {
        puts("Wrong Answer");
    }
    else if(systemTest == false)
    {
        puts("Why Wrong!!!");
    }
    else 
    {
        puts("Accepted");
    }
}