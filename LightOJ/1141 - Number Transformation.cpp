/**********************************************************
Status:     Accepted
Problem:    lightOJ 1141
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
vector<int> primeFactor[1002];
void primeFactorize(int n)
{
    int k;
    for(int i=4;i<=n;i++)
    {
        k=i;
        if(k%2==0)
        {
            primeFactor[i].push_back(2);
            while(k%2==0)
            {
                k/=2;
            }
        }
        for(int j=3;j<=k && j<i;j+=2)
        {
            if(k%j==0)
            {
                primeFactor[i].push_back(j);
                while(k%j==0)
                {
                    k/=j;
                }
            }
        }
    }
}
int bfs(int from, int to)
{
    if(from==to)
        return 0;
    int visited[1002], level[1002];
    for(int i=1;i<=1000;i++)
        visited[i]=0;
    queue<int> q;
    level[from]=0;
    q.push(from);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<primeFactor[u].size();i++)
        {
            int v=u+primeFactor[u][i];
            if(v<=to)
            {
                if(visited[v]==0)
                {
                    visited[v]=1;
                    level[v]=level[u]+1;
                    if(v==to)
                        return level[v];
                    q.push(v);
                }
            }
        }
    }
    return -1;
}
int main()
{
    //freopen("1141.txt", "r", stdin);
    primeFactorize(1000);
    int test, s, t, cas;
    scanf("%d", &test);
    for(cas=1;cas<=test;cas++)
    {
        scanf("%d %d", &s, &t);
        printf("Case %d: %d\n", cas, bfs(s, t));
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/

