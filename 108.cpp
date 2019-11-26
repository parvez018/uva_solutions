#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 110

int arr[MAX][MAX];
int subArray[MAX][MAX];
int squareSize,sum;

void printSubArr()
{
    int i,j;
    for(i=1;i<=squareSize;i++)
    {
        for(j=1;j<=squareSize;j++)
        {
            printf("%d ",subArray[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    freopen("in.txt","r",stdin);

    int i,j,m,n,k;
    int maxSum;
    while((scanf("%d",&squareSize))!=EOF)
    {
        for(i=1;i<=squareSize;i++)
        {
            for(j=1;j<=squareSize;j++)
            {
                scanf("%d",&arr[i][j]);
                subArray[i][j]=0;
            }
        }
        for(i=1;i<=squareSize;i++)
        {
            for(j=1;j<=squareSize;j++)
            {
                sum=0;
                for(m=1;m<=i;m++)
                {
                    sum+=arr[m][j];
                }
                subArray[i][j]=subArray[i][j-1]+sum;
            }
        }
        //printSubArr();
        maxSum=0;
        for(i=1;i<=squareSize;i++)
        {
            for(j=i;j<=squareSize;j++)
            {
                sum=0;
                for(k=1;k<=squareSize;k++)
                {
                    if(0<=sum+subArray[j][k]-subArray[i-1][k]-(subArray[j][k-1]-subArray[i-1][k-1]))
                    {
                        sum=sum+subArray[j][k]-subArray[i-1][k]-(subArray[j][k-1]-subArray[i-1][k-1]);
                        if(maxSum<sum)maxSum=sum;
                    }
                    else sum=0;
                }
            }
        }
        printf("%d\n",maxSum);


    }
    return 0;
}
