#include <cstdio>
#include <algorithm>
#include <functional>
int N, K, ans;
constexpr auto SIZE = 100'007;
struct c1{};
struct c2{};
struct c3{};
struct Data
{
    int a;
    int b;
    int c;

    int GetScore(c1 cmp)
    {
        return a + b;
    }
    int GetScore(c2 cmp)
    {
        return a + c;
    }
    int GetScore(c3 cmp)
    {
        return b + c;
    }
    bool operator < (const Data &r) const
    {
        return a <r.a;
    }

} data[SIZE], tmp[SIZE];


struct Cmp1
{
    bool operator()(const Data &x, const Data &y) const
    {
        return x.a + x.b <= y.a + y.b;
    }
};

struct Cmp2
{
    bool operator()(const Data &x, const Data &y) const
    {
        return x.a + x.c <= y.a + y.c;
    }
};

struct Cmp3
{
    bool operator()(const Data &x, const Data &y) const
    {
        return x.b + x.c <= y.b + y.c;
    }
};


template < typename Data, typename T>
void Merge(Data data[], int s, int m, int e, const T& cmp)
{
    int i = s;
    int j = m + 1;
    int k = s;

    while (i <= m && j <= e)
    {
        if (cmp(data[i], data[j]))
        {
            tmp[k++] = data[i++];
        }
        else
        {
            tmp[k++] = data[j++];
        }
    }

    if (i <= m)
    {
        for (int t = i; t <= m; t++)
        {
            tmp[k++] = data[t];
        }
    }
    else
    {
        for (int t = j; t <= e; t++)
        {
            tmp[k++] = data[t];
        }
    }

    for (int i = s; i <= e; i++)
    {
        data[i] = tmp[i];
    }
    return;
}

template < typename Data, typename T>
void MergeSort(Data data[], int s, int e, T cmp)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        MergeSort(data, s, mid, cmp);
        MergeSort(data, mid + 1, e, cmp);
        Merge(data, s, mid, e, cmp);
    }
}
template <typename T>
int totalPower(int K, T cmp)
{
    int sum = 0;
    for (int i = N - 1; i >= N - K; i--)
    {
        sum += data[i].GetScore(cmp);
    }
    return sum;
}

template <typename T>
inline T MAX(T A, T B)
{
    return A > B ? A : B;
}

int main()
{
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d %d %d", &data[i].a, &data[i].b, &data[i].c);
    }

    MergeSort(data, 0, N - 1, Cmp1());

    ans = MAX(ans, totalPower(K, c1()));

    MergeSort(data, 0, N - 1, Cmp2());

    ans = MAX(ans, totalPower(K, c2()));

    MergeSort(data, 0, N - 1, Cmp3());

    ans = MAX(ans, totalPower(K, c3()));

    printf("%d", ans);

    return 0;
}