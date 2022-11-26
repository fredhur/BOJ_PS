#include <cstdio>
#include <cmath>
#include <vector>
int PrimeNumbers[4000005];
int twoPointer[4000005];
class Eratos
{
public:
    Eratos() = default;
    Eratos(int initNum)
    {
        num_ = initNum;
        for (int i = 2; i <= initNum; i++)
        {
            PrimeNumbers[i] = i;
        }

        for (int i = 2; i <= sqrt(initNum); i++)
        {
            if (PrimeNumbers[i] == 0)
                continue;

            for (int j = i * i; j <= initNum; j += i)
            {
                PrimeNumbers[j] = 0;
            }
        }
    }
    ~Eratos() = default;

    int Solve()
    {
        int idx = 0;
        // init all prime numbers to two Pointer array.
        for (int i = 2; i <= num_; i++)
        {
            if(PrimeNumbers[i] != 0)
            {
                twoPointer[idx++] = PrimeNumbers[i];
            }
        }
        
        
        int start = 0, end = 0, ans=0, sum=0;
        while(end <=  idx)
        {
            if(num_ <= sum)
            {
                sum -= twoPointer[start];
                start++;
            }
            else 
            {
                
                sum += twoPointer[end];
                end++;
            }
            if(sum == num_)
            {
                ans++;
            } 
        
        }
        return ans;
    }

private:
    int num_;
};

int main()
{
    int N; 
    scanf("%d", &N);
    Eratos solve(N);

    printf("%d\n", solve.Solve());
    return 0;
}