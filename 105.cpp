#include<iostream>
using namespace std;

int main()
{
    int co_x[10000];
    int i;


    for(i=0;i<10000;i++)co_x[i]=0;

    int start,end=0;
    int ss,hh,ee;
    i=0;
    while(cin>>ss>>hh>>ee)
    {
        if(i==0)start=ss;
        i++;
        if(ee>end)end=ee;

        for(int j=ss;j<ee;j++)
        {
            if(co_x[j]<hh)co_x[j]=hh;
        }
    }

    int current=start;
    cout<<current<<" "<<co_x[current]<<" ";
    //for(i=start;i<=end;i++)
    for(i=start;i<end;i++)
    {
        if(co_x[current]!=co_x[i])
        {
            cout<<i<<" "<<co_x[i];
            cout<<" ";
            current=i;
        }
    }

cout<<end<<" "<<co_x[i]<<'\n';
return 0;
}

