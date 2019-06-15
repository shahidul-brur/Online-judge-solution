//Accepted
#include <bits/stdc++.h>
using namespace std;
#define MIN(a, b) (a<b ? a:b)
int forbiden[10002], dis[10002], visited[10002];
int start, target;
int m[]={1, 10, 100, 1000};
int bfs(int n)
{
    queue<int> q;
    q.push(n);
    visited[n]=1;
    dis[n]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<=3;i++)
        {
            int digit, v1, v2;
            digit = (u/m[i])%10;
            if(digit==0)
                v1=u+9*m[i];
            else v1=u-m[i];

            if(digit==9)
                v2=u-9*m[i];
            else v2=u+m[i];

            if(forbiden[v1]==0 && visited[v1]==0)
            {
                dis[v1]=dis[u]+1;
                visited[v1]=1;
                q.push(v1);
            }
            if(forbiden[v2]==0 && visited[v2]==0)
            {
                dis[v2]=dis[u]+1;
                q.push(v2);
                visited[v2]=1;
            }
        }
    }
    return dis[target];
}
int main()
{
    //freopen("10067.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int test, i, a, b, c, d, forbid, f;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        start = a*1000 + b*100 + c*10 + d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        target = a*1000 + b*100 + c*10 + d;

        memset(forbiden, 0, sizeof(forbiden));
        memset(visited, 0, sizeof(visited));
        memset(dis, 0, sizeof(dis));

        scanf("%d", &forbid);
        for(i=1;i<=forbid;i++)
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            f = a*1000 + b*100 + c*10 + d;
            forbiden[f]=1;
        }
        if(start==target)
            printf("0\n");
        else
        {
            f=bfs(start);
            if(dis[target]==0)
                printf("-1\n");
            else
                printf("%d\n", dis[target]);
        }
    }
    return 0;
}
