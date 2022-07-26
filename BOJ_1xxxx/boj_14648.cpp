#include <cstdio>
using ll = long long;
int n,q;
int arr[1005];
ll psum[1005];
template <typename T>
void Swap(T &a, T&b)
{
    T t = a;
    a = b, b=t;
}

int main()
{
    scanf("%d %d", &n, &q);
    for(int i=1; i<=n; i++)
    {
        scanf(" %d", &arr[i]);
    }
    psum[0] = arr[0] = 0;
    for(int i=1; i<=n; i++)
    {
        psum[i] = psum[i-1]+ arr[i];
    }

    for(int i=0; i<q; i++)
    {
        int cmd;
        scanf(" %d", &cmd);
        if(cmd == 1)
        {
            int a, b;
            scanf(" %d %d", &a, &b);
            printf("%lld\n",psum[b]-psum[a]+arr[a]);
            for(int i=a; i<b; i++)
            {
                psum[i] = psum[i] + arr[b] - arr[a];    
            }
            Swap(arr[a], arr[b]);
            
            
        }
        else if(cmd==2)
        {
            int a,b, c,d;
            scanf(" %d %d %d %d", &a, &b, &c, &d);
            const auto l = psum[b]-psum[a]+arr[a];
            const auto r = psum[d] - psum[c]+arr[c];

            printf("%lld\n", l-r);
        }
    }
}