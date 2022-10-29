// Title : 휴게소 세우기 https://www.acmicpc.net/problem/1477
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,L;
vector<int> road;

void input()
{
    scanf("%d%d%d", &N, &M, &L);
    for(int i=0; i<N; i++)
    {   
        int h;
        scanf(" %d", &h);
        road.push_back(h);
        
    }
    road.push_back(0); road.push_back(L);
    sort(road.begin(),road.end());
}
bool check(int mid)
{

    int cnt = 0;

    for(int i=1; i< road.size(); i++)
    {
        cnt += (road[i]-road[i-1])/mid;

        if((road[i]-road[i-1])%mid ==0)
        {
            cnt--;
        }
    }

    return cnt >M;
}
void bsearch()
{
    int s=1,e=L-1;
   
    while(s<=e)
    {
        int mid = (s+e)/2;

        if(check(mid))
        {
           
            s = mid+1;
        }
        else 
        {
             e = mid -1;
        }
    }
    printf("%d", s);
}
int main()
{
    input();
    bsearch();
    return 0;
}