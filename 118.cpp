#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX 60
#define EAST 0
#define NORTH 1
#define WEST 2
#define SOUTH 3

int main()
{
    freopen("in.txt","r",stdin);
    char grid[MAX][MAX];
    int startX,startY,row,col,currDir;
    bool isLost;
    char commands[110],startDir;
    int mov[4][2]={{1,0},{0,1},{-1,0},{0,-1}};

    scanf("%d%d",&row,&col);
    memset(grid,0,sizeof(grid));

    while((scanf("%d%d%*c%c%*c",&startX,&startY,&startDir))!=EOF)
    {
        scanf("%s",commands);
        isLost=false;
        if(startDir=='E')currDir=EAST;
        else if(startDir=='W')currDir=WEST;
        else if(startDir=='N')currDir=NORTH;
        else if(startDir=='S')currDir=SOUTH;
        //printf("%s %d %d %c\n",commands,startX,startY,currDir);
        int i=0;
        while(commands[i])
        {
            if(!isLost)
            {
                if(commands[i]=='R')
                {
                    currDir=(currDir-1+4)%4;
                }
                else if(commands[i]=='L')
                {
                    currDir=(currDir+1)%4;
                }
                else if(commands[i]=='F')
                {
                    startX+=mov[currDir][0];
                    startY+=mov[currDir][1];
                    if(startX<0 || startX>row || startY<0 || startY>col)
                    {
                        //isLost=true;
                        startX-=mov[currDir][0];
                        startY-=mov[currDir][1];

                        if(grid[startX][startY]==0)
                        {
                            grid[startX][startY]=1;
                            isLost=true;
                        }
                    }
                }
            }
            i++;
        }
        printf("%d %d ",startX,startY);
        if(currDir==EAST)printf("E");
        else if(currDir==WEST)printf("W");
        else if(currDir==NORTH)printf("N");
        else if(currDir==SOUTH)printf("S");

        if(isLost)printf(" LOST");
        printf("\n");
    }

    return 0;
}
