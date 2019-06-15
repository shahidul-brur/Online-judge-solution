//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> g[303];
int d[303], parent[303], source, dest;
void bfs()
{
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            if(d[v]==0)
            {
                d[v]=d[u]+1;
                parent[v]=u;
                q.push(v);
            }
        }
    }
}
int main()
{
    freopen("627.txt", "r", stdin);
    int i, t, j, k, cas=1, n, couple, r, m, order[305], id;
    int A, B;
    char temp[10000];
    while(scanf("%d", &n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s", temp);
            id=-1;
            char *p=strtok(temp, "-");
            while(p!=NULL)
            {
                p=strtok(NULL, ", ");
                sprintf(temp, "%s\n", p);
                sscanf(temp, "\n%d", &r);
                temp[0]='\0';
                if(r>=0)
                    g[i].push_back(r);
                r=-1;
            }
        }

        printf("-----\n");
        scanf("%d", &m);
        while(m--)
        {
            scanf("%d %d", &source, &dest);
            memset(d, 0, sizeof(d));
            memset(parent, 0, sizeof(parent));
            memset(order, 0, sizeof(order));
            bfs();
            if(d[dest]==0)
                printf("connection impossible\n");
            else
            {
                for(k=0,j=dest;j>=0;k++)
                {
                    //printf("%d\n", k);
                    order[k]=j;
                    if(j==source)
                        break;
                    j=parent[j];
                }
                for(j=k;j>=0;j--)
                {
                    if(j<k)
                        printf(" ");
                    printf("%d", order[j]);
                }
                printf("\n");
            }
        }
        for(j=0;j<=n;j++)
            g[j].resize(0);
    }
    return 0;
}
