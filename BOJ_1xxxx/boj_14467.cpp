#include <cstdio>
class Cow
{
public:
    Cow()
    {
        pos_ = -1;
        cnt_ = 0;
    }
    int GetCnt()const
    {
        return cnt_;
    }
    void SetPos(int pos)
    {
        if (pos_ == -1)
        {
            pos_ = pos;
        }
        else
        {
            cnt_ += (pos_ != pos);
            pos_ = pos;
        }
    }
private:
    int pos_;
    int cnt_;
} cow[11];
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int c, pos;
        scanf(" %d %d", &c, &pos);
        cow[c].SetPos(pos);
    }
    int cnt =0;
    for(int i=1; i<=10; i++)
    {
        cnt += cow[i].GetCnt();
    }
    printf("%d", cnt);
    return 0;
}