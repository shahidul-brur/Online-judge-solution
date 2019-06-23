/*==============================================*\ 
ID:          shahidul_brur

Name:     Md. Shahidul Islam           
Study:      CSE, BRUR                 
Address:  Rangpur, Bangladesh
                
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English) 
\*===============================================*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = (int)2e5+100;
const int LOGN = 20;
vector<int> g[maxn];
ll a[maxn];
ll w[maxn];
int ans[maxn], par[maxn];
vector<ll> cost;
vector<int> node;
void dfs(int u)
{
    node.push_back(u);
    for(int v:g[u])
    {
        if(!cost.empty())
            cost.push_back(cost.back()+w[v]);
        else cost.push_back(w[v]);
        if(a[v]>=w[v])
        {
            int lo = 0, hi=node.size()-1, idx=0;
            while(lo<=hi)
            {
                int mid =(lo+hi)/2;
                ll pre = 0;
                if(mid>0) pre = cost[mid-1];
                if(a[v]>=cost.back()-pre)
                {
                    idx=mid;
                    hi=mid-1;
                }
                else lo=mid+1;
            }
            ans[node.back()]++;
            ans[par[node[idx]]]--;
        }
        dfs(v);
        cost.pop_back();
    }
    node.pop_back();
}
void dfs2(int u)
{
    for(int v:g[u])
    {
        dfs2(v);
        ans[u]+=ans[v];
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, u;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        cin>>u>>w[i];
        g[u].push_back(i);
        par[i] = u;
    }
    dfs(1);
    dfs2(1);
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    return 0;
}