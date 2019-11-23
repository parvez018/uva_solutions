#include<stdio.h>
int main()
{
    // freopen("in.txt", "r", stdin);
    long long int n1,n2,j,temp,k;
    long int long i,count=0;
    while(scanf("%lld%lld",&n1,&n2)==2)
    {
      printf("%lld %lld ",n1,n2);
        if(n1>n2)
                {temp=n1;
                 n1=n2;
                 n2=temp;
                }
                count=0;
      for(k=n1;k<=n2;k++)
      {j=k;


        for(i=1;j!=1;i++)
        {
        if(j%2==1)
                {j=3*j+1;
                }
        else
            {j=j/2;
            }
        }

        if(i>count)count=i;

      }
      printf("%lld\n",count);


    }

  return 0;
}
