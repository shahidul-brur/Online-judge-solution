/**********************************************************
Status:     A
Problem:    UVa 514 - Rails
Author:     Md. Shahidul Islam,
            Department of Computer Science and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Date created: 10 - 07 - 2015
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int N, du[22], track;
typedef struct cd
{
    int total_duration;
    int total_track;
};
cd findWay(int sum, int t, int p)
{
    cd C;
    C.total_track=t;
    C.total_duration=sum;
    if(p>=track || sum>N)
        return C;
    cd c1;
    c1.total_track=0;
    c1.total_duration=0;
    if(sum+du[p]<=N)
        c1=findWay(sum+du[p], t+1, p+1);
    cd c2=findWay(sum, t, p+1);
    if(c1.total_track>c2.total_track)
     {
         C.total_track+=c1.total_track;
         C.total_duration+=c1.total_duration;
     }
    else if(c1.total_track==c2.total_track && c1.total_duration>c2.total_duration)
    {
         C.total_track+=c1.total_track;
         C.total_duration+=c1.total_duration;
     }
    else if(c1.total_track==c2.total_track && c1.total_duration<c2.total_duration)
     {
         C.total_track+=c2.total_track;
         C.total_duration+=c2.total_duration;
     }
    else if(c1.total_track==c2.total_track && c1.total_duration==c2.total_duration)
    {
         C.total_track+=c1.total_track;
         C.total_duration+=c1.total_duration;
     }
    else if(c1.total_track<c2.total_track)
     {
         C.total_track+=c2.total_track;
         C.total_duration+=c2.total_duration;
     }
     printf("%d %d\n", C.total_track, C.total_duration);
     return C;
}
int main()
{
    freopen("624.txt", "r", stdin);
    int index[22], maxTrack, maxDu, i, j, sum, t, way[22][22], ans;
    while(scanf("%d", &N)!=EOF)
    {
        scanf("%d", &track);
        for(i=0;i<track;i++)
        {
            scanf("%d", &du[i]);
            index[du[i]]=i;
        }
        cd ans=findWay(0, 0, 0);
        printf("%d %d\n", ans.total_track, ans.total_duration);
        //for(i=0;i<maxTrack;i++)
            //printf("%d ", du[way[ans][i]]);
        //printf("sum:%d\n", maxDu);
    }
    return 0;
}
/**********************************************************
About this problem:



************************************************************/
