#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct Pos
{
    int x;
    int y;
};
int main()
{
    Pos pos[4];
    vector<Pos> v;
    scanf("%d %d %d %d", &pos[0].x, &pos[0].y, &pos[1].x, &pos[1].y);
    scanf(" %d %d %d %d", &pos[2].x, &pos[2].y, &pos[3].x, &pos[3].y);
    for(auto i=0; i< std::size(pos); i++)
    {
        v.push_back(pos[i]);
    }
    std::sort(v.begin(), v.end(), [](Pos &lhs, Pos&rhs){return lhs.x < rhs.x;});
    const auto width = std::abs(v[0].x - v[3].x);

    std::sort(v.begin(), v.end(), [](Pos &lhs, Pos&rhs){return lhs.y < rhs.y;});
    const auto height = std::abs(v[0].y - v[3].y);

    const auto ret = std::max(width,height);

    printf("%d", ret*ret);
}
