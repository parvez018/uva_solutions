#include<iostream>
#include<cstring>

using namespace std;
int main()
{
    char name[][4]={"BCG","BGC","CBG","CGB","GBC","GCB"};

    unsigned long long arr[9],min,temp,sum=0;

    while(1)
    {
        sum=0;
        int i,check=1;
        for(i=0;i<9;i++)
        {
            if(cin>>arr[i])sum+=arr[i];

            else
            {
                check=2;
                break;
            }
        }
        if(check==2)break;
        i=0;
        min=sum-(arr[0]+arr[5]+arr[7]);

        temp=sum-(arr[0]+arr[4]+arr[8]);
        if(temp<min)
        {
            min=temp;
            i=1;
        }

        temp=sum-(arr[2]+arr[3]+arr[7]);
        if(temp<min)
        {
            min=temp;
            i=2;
        }

        temp=sum-(arr[2]+arr[4]+arr[6]);
        if(temp<min)
        {
            min=temp;
            i=3;
        }

        temp=sum-(arr[1]+arr[3]+arr[8]);
        if(temp<min)
        {
            min=temp;
            i=4;
        }

        temp=sum-(arr[1]+arr[5]+arr[6]);
        if(temp<min)
        {
            min=temp;
            i=5;
        }

        cout<<name[i]<<' '<<min<<'\n';

    }
    return 0;
}
