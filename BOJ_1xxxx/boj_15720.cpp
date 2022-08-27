#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int B, C, D;
int Total(vector<int> &v)
{
    auto sum = 0;
    for (auto &i : v)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    vector<int> bugger, juice, side;
    int m;
    scanf("%d %d %d", &B, &C, &D);
    m = std::min(std::min(B, C), D);
    for (int i = 0; i < B; i++)
    {
        int b;
        scanf(" %d", &b);
        bugger.push_back(b);
    }
    for (int i = 0; i < C; i++)
    {
        int j;
        scanf(" %d", &j);
        juice.push_back(j);
    }
    for (int i = 0; i < D; i++)
    {
        int s;
        scanf(" %d", &s);
        side.push_back(s);
    }
    std::sort(bugger.begin(), bugger.end());
    std::sort(juice.begin(), juice.end());
    std::sort(side.begin(), side.end());
    int total = 0;
    total += Total(bugger);
    total += Total(juice);
    total += Total(side);
    
    
    int discount = 0;
    for(int i=0; i<m; i++)
    {
        int sum = *(bugger.end()-1) + *(juice.end()-1) + *(side.end()-1);
        sum = sum * 0.9;
        
        discount += sum;

        bugger.erase(bugger.end()-1);
        juice.erase(juice.end()-1);
        side.erase(side.end()-1);
    }
    discount += Total(bugger) + Total(juice) + Total(side);
    printf("%d\n%d\n", total, discount);
}