#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 30

vector<int> iArray;
int lArray[MAX];
int arrInput[MAX];
int orderIndex[MAX];

int n;
int lisLengthINC,lisLengthDEC;
int corSeq[MAX];


void lisBinarySearchINC()
{
    iArray.clear();
    int i=0;
    int start,mid,end;
    lisLengthINC=-1;
    for(i=0;i<=n;i++)lArray[i]=0;
    for(i=0;i<n;i++)
    {
        start=0;
        end=iArray.size();
        while(start<end)
        {
            mid=(start+end)/2;
            if(orderIndex[arrInput[i]]<orderIndex[iArray[mid]])
                end=mid;
            else start=mid+1;
        }

        if(end==iArray.size())
        {
            iArray.push_back(arrInput[i]);
            lArray[i]=iArray.size();
        }
        else
        {
            iArray[end]=arrInput[i];
            lArray[i]=end+1;
        }
        if(lisLengthINC<=lArray[i])
        {
            lisLengthINC=lArray[i];
        }
    }
}


int main()
{
    //freopen("in.txt","r",stdin);

    int i,a;
    int score;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        corSeq[a-1]=i+1;
        orderIndex[i+1]=a;
    }
    while((scanf("%d",&i))!=EOF)
    {
        score=0;

        arrInput[i-1]=1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&a);
            arrInput[a-1]=i+1;
        }
        lisBinarySearchINC();
        printf("%d\n",lisLengthINC);
    }
    return 0;
}
