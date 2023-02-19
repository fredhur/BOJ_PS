#include <iostream>
int N;
struct Data
{
    Data()
    {
        in =0,out=0;
        isValid = false;
    }
    int in;
    int out;
    bool isValid;
};
Data id[200'006];

int main()
{
    scanf("%d", &N);
    int ans = 0;
    for(int i=0; i<N; i++)
    {
        int a, b;
        scanf(" %d %d", &a, &b);
        if(id[a].isValid == true)
        {
            continue;
        }
        if(b==0) // out
        {
           id[a].in--;

           if(id[a].in <0 )
           {
                id[a].isValid = true;
              ///  printf("whom id : %d\n", a);
                ans++;
           }
        }
        else // in
        {
            id[a].in++;

            if(id[a].in > 1)
            {
                id[a].isValid = true;
                //printf("whom id : %d\n", a);
                ans++;
            }

        }

    }
    for(int i=1; i<= 200000; i++)
    {
        if((id[i].in !=  0) && id[i].isValid == false)
        {
            ans++;
        }
    }
    
    
    printf("%d", ans);
    return 0;
}