#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using uint = unsigned int;
vector<uint> width, height;
vector<uint> reArrangedWidth, reArrangedHeight;
int main()
{
    uint w, h, N;
    scanf("%u %u", &w, &h);
    scanf(" %u", &N);
    width.push_back(w), height.push_back(h);
    width.push_back(0), height.push_back(0);
    for (uint i = 0; i < N; i++)
    {
        uint idx, c;
        scanf(" %u %u", &idx, &c);
        if (idx == 0)
        {
            height.push_back(c);
        }

        else
        {
            width.push_back(c);
        }
    }

    std::sort(width.begin(), width.end(), [](uint &a, uint &b)
              { return a < b; });
    std::sort(height.begin(), height.end(), [](uint &a, uint &b)
              { return a < b; });
    uint max = 0;

    for (auto i = 1; i < width.size(); i++)
    {
        reArrangedWidth.push_back(width[i] - width[i - 1]);
    }
    for (auto i = 1; i < height.size(); i++)
    {
        reArrangedHeight.push_back(height[i] - height[i - 1]);
    }
    uint ret =0;

    for(auto &i: reArrangedHeight)
    {
        for(auto &j : reArrangedWidth)
        {
            ret = std::max(ret, i*j);
        }
    }
    printf("%d", ret);
    return 0;
}