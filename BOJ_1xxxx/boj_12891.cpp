#include <cstdio>
char str[1000007];
struct Data
{
    int cntA;
    int cntC;
    int cntG;
    int cntT;
    int minA;
    int minC;
    int minG;
    int minT;
    Data(const int &A, const int &C, const int &G, const int &T)
    {
        cntA = cntC = cntG = cntT = 0;
        minA = A, minC = C, minG = G, minT = T;
    }
    void CalcCnt(char ch)
    {
        switch (ch)
        {
        case 'A':
            cntA++;
            break;
        case 'C':
            cntC++;
            break;
        case 'G':
            cntG++;
            break;
        case 'T':
            cntT++;
            break;
        default:
            break;
        }
    }
    void MinusCnt(char ch)
    {
        switch (ch)
        {
        case 'A':
            cntA--;
            break;
        case 'C':
            cntC--;
            break;
        case 'G':
            cntG--;
            break;
        case 'T':
            cntT--;
            break;
        default:
            break;
        }
    }
    bool isOkay() const
    {
        return (cntA >= minA &&
                cntC >= minC &&
                cntG >= minG &&
                cntT >= minT);
    }
};
int main()
{
    int S, P, ans = 0;

    int minA, minC, minG, minT;
    scanf("%d %d", &S, &P);
    scanf(" %s", str);
    scanf(" %d %d %d %d", &minA, &minC, &minG, &minT);
    Data data(minA, minC, minG, minT);

    for (int i = 0; i < P; i++)
    {
        data.CalcCnt(str[i]);
    }
    ans += (data.isOkay());
    for (int i = 0; i < S - P; i++)
    {
        data.MinusCnt(str[i]);
        data.CalcCnt(str[i + P]);
        ans += (data.isOkay());
    }
    printf("%d\n", ans);
    return 0;
}