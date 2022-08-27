#include <cstdio>
struct Pos
{
    int x;
    int y;
};
enum Direction
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};
Pos snail;
int dir = NORTH;
int time;
bool moveSnail(Direction dir, int &total, int delta, int move, int &pos)
{
    for(int i=0; i<move ; i++)
    {
        pos += delta;
        total++;
        if(total == time)
        {
            return true;
        }
    }
    return false;
}

void process()
{
    int total = 0;
    int move = 1;

    if (time == 0)
        return;

    for (int i = 1;; i++)
    {
        switch (dir)
        {
        case NORTH:
            if(moveSnail((Direction)dir, total, 1, move, snail.y))
            {
                return;
            }
            break;
        case SOUTH:
            if(moveSnail((Direction)dir, total, -1, move,  snail.y))
            {
                return;
            }
            break;
        case EAST:
            if(moveSnail((Direction)dir, total, 1, move, snail.x))
            {
                return;
            }
            break;
        case WEST:
            if(moveSnail((Direction)dir, total, -1 ,move, snail.x))
            {
                return;
            }
            break;
        }
        move += (i%2 ==0);
        dir = (dir + 1) % 4;
    }
}

int main()
{

    scanf("%d", &time);

    process();
    printf("%d %d\n", snail.x, snail.y);

    return 0;
}