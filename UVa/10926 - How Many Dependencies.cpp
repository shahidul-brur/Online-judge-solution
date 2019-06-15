//Accepted

#include<bits/stdc++.h>
using namespace std;
int d[102], calculated[102];
vector<int> depend[102];
set<int> lst[102];
void calDepend(int task)
{
    calculated[task]=1;
    for(int i=0;i<d[task];i++)
    {
        lst[task].insert(depend[task][i]);
        if(calculated[depend[task][i]]==0)
            calDepend(depend[task][i]);
        lst[task].insert(lst[depend[task][i]].begin(), lst[depend[task][i]].end());
    }
}
int main()
{
    //freopen("10926.txt", "r", stdin);
    int n,i,j,maxi,ans,f;
    while(scanf("%d",&n)&&n!=0)
    {
        ans=1;
        maxi=0;
        memset(calculated, 0, sizeof(calculated));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&d[i]);
            for(j=1;j<=d[i];j++)
            {
                scanf("%d",&f);
                depend[i].push_back(f);
            }
        }
        for(i=1;i<=n;i++)
        {
            if(calculated[i]==0)
                calDepend(i);
            if(lst[i].size()>maxi)
            {
                maxi=lst[i].size();
                ans=i;
            }
        }
        printf("%d\n",ans);
        for(i=1;i<=n;i++)
        {
            depend[i].clear();
            lst[i].clear();
        }
    }
    return 0;
}
