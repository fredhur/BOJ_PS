#include <cstdio>
int N;
int building[1007];
int end;
int start;
int leftMaxPos;
int rightMaxPos;
int FromLeft()
{
    int s = start;
    int leftHigh = 0;
    int leftSum = 0;
    leftMaxPos = s;
    for (int i = s; i <= end; i++)
    {
        if (leftHigh < building[i])
        {
            leftHigh = building[i];
            leftMaxPos = i;
        }
    }
    leftHigh = 0;
    for (int i = s; i <= leftMaxPos; i++)
    {
        if (leftHigh < building[i])
        {
            leftHigh = building[i];
        }
        leftSum += leftHigh;
    }

    return leftSum;
}

int FromRight()
{
    int e = end;
    int rightHigh = 0;
    int rightSum = 0;
    rightMaxPos = e;

    for (int i = e; i >= start; i--)
    {
        if (rightHigh < building[i])
        {
            rightHigh = building[i];
            rightMaxPos = i;
        }
    }

    rightHigh = 0;
    for (int i = e; i >= rightMaxPos; i--)
    {
        if (rightHigh < building[i])
        {
            rightHigh = building[i];
        }
        rightSum += rightHigh;
    }

    return rightSum;
}

int main()
{
    scanf("%d", &N);
    start = 0x7fffffff;
    end = -1;
    for (int i = 0; i < N; i++)
    {
        int pos, high;
        scanf(" %d %d", &pos, &high);
        building[pos] = high;

        if (start > pos)
        {
            start = pos;
        }
        if (end < pos)
        {
            end = pos;
        }
    }

    const auto leftSum = FromLeft();
    const auto rightSum = FromRight();
    const auto diff = rightMaxPos - leftMaxPos - 1;

    if (rightMaxPos == leftMaxPos)
    {
        printf("%d\n", leftSum + rightSum - building[leftMaxPos]);
    }
    else
    {
        printf("%d\n", leftSum + rightSum + diff * building[rightMaxPos]);
    }

    return 0;
}