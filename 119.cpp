#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX 20

char names[MAX][MAX];
int frndCount;
int money[MAX];

int frndIndex(char singleName[MAX])
{
    for(int i=0;i<frndCount;i++)
    {
        if(strcmp(names[i],singleName)==0)return i;
    }
}

int main()
{
    freopen("in.txt","r",stdin);

    int i,j;
    int givMoney,givPerson;
    int donorIndex;
    char arr[MAX];
    scanf("%d",&frndCount);
    while(true)
    {
        for(i=0;i<frndCount;i++)
        {
            scanf("%s",names[i]);
            money[i]=0;
        }
        for(i=0;i<frndCount;i++)
        {
            scanf("%s",arr);
            donorIndex=frndIndex(arr);
            scanf("%d%d",&givMoney,&givPerson);
            if(givMoney>0 && givPerson>0)
            {
                money[donorIndex]-=(givMoney-givMoney%givPerson);
                givMoney/=givPerson;
            }
            for(j=0;j<givPerson;j++)
            {
                scanf("%s",arr);
                money[frndIndex(arr)]+=givMoney;
            }
        }
        for(i=0;i<frndCount;i++)
        {
            printf("%s %d\n",names[i],money[i]);
        }
        if((scanf("%d",&frndCount))!=EOF)printf("\n");
        else break;
    }
    return 0;
}
