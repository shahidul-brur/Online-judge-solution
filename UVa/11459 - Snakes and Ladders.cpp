//Accepted

#include<stdio.h>
#include <iostream>
#include<vector>
#define MAX 1000010
using namespace std;
int main()
{
    freopen("11459.txt", "r", stdin);
    int t,p,s,d,i,j,k,from[110],to[110],go,br;
    vector<int> pos(MAX);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&p,&s,&d);
        for(i=1;i<=s;i++)
        {
            scanf("%d %d",&from[i],&to[i]);
        }
        br=0;
        for(i=1;i<=p;i++)
            pos.at(i)=1;
        for(i=1,j=1;i<=d;i++,j++)
        {
            scanf("%d",&go);
            if(br==0){
            pos.at(j)+=go;
            for(k=1;k<=s;k++)
            {
                if(pos.at(j)==from[k])
                {
                    pos.at(j)=to[k];
                    break;
                }
            }
            if(pos.at(j)==100)
                br=1;
            if(j==p)
                j=0;
                }
        }
        for(i=1;i<=p;i++)
        {
            printf("Position of player %d is %d.\n",i,pos.at(i));
        }
    }
    return 0;
}
