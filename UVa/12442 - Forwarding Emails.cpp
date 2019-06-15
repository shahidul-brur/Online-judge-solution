//Accepted, after 16 hrs tried !

#include <bits/stdc++.h>
using namespace std;
int nxt[50004], p[50004], d[50004], path[50004];
int maxi, n, choose, vis[50002], reach[50002];
void dfs(int u)
{
    //cout << "\n --- dfs " << u << " ---\n";
    vis[u] = 1;
    int v = nxt[u];
    p[v] = u; //parent of v = u
    d[u]=1;
    d[v]=2;
    int l = 2, from, to, now=u;
    for(;;)
    {
        //cout << v << ", prev =" << now << "\n";
        if(reach[v]!=0)
        {
            from = v;
            to = now;
            goto rev;
        }
        if(vis[v]==1)
        {
            from = v;
            to = now;
            break;
        }
        else
        {   
            p[v] = now;
            d[v] = d[now] + 1;
            vis[v] = 1;
            now = v;
            v = nxt[v];
        }
    }
    //cout << "  from " << from << " - " << to << "\n";
    reach[to] = d[to] - d[from]+1;
    //cout << to << " = " << reach[to] << "\n";
    reach[from] = reach[to];
    //cout << from << " = " << reach[from] << "\n";
    //if(reach[from]!=0)
        //p[from] = to;
    now = to;
    for(;;)
    {
        if(now==from || now==0)
            break;
        //cout << now << " ##\n";
        reach[now] = reach[from];
        now=p[now];
    }
    now = p[from];
    //cout << now << " -> " << u << " \n";
    
    rev:
        for(l=1;;)
        {
            //cout << reach[from] << " ....\n";
            reach[now] = reach[from] + l;
            //cout << now << " = " << reach[now] << "\n";
            if(now==u || now==0)
                break;
            now = p[now];
            l++;
        }
    
    //if(now==u) cout << "---- ok ----\n";
}
int main()
{
    //freopen("12442.txt", "r", stdin);
    int t, cas, i, j, u, v, sent, r;
    vector<int> g[50002];
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        cin>>n;
        maxi=-1;
        choose=0;
        for(i=1;i<=n;i++)
        {
            cin>>u>>v;
            nxt[u] = v;
            reach[i] = vis[i] = p[i] = d[i] = 0;
        }
        
        for(i=1;i<=n;i++)
        {
            if(vis[i]==0)
                dfs(i);
            //cout << "   # " << i << " = " << reach[i] << "\n";
            if(reach[i]>maxi)
            {
                maxi = reach[i];
                choose = i;
            }
        }
        cout<<"Case "<<cas<<": "<<choose<< '\n';
    }
    return 0;
}
