#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    double f,s;
    while(cin>>f>>s)
    {
        if(f<=0 || s==0)continue;

        double ans=pow(s,1/f);
        cout<<fixed<<setprecision(0)<<ans<<'\n';
    }

    return 0;
}
