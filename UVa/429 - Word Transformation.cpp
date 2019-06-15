//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<string> dic;
vector<int> g[202];
int d[202], source, dest;
string A, B;
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
                q.push(v);
            }
        }
    }
}
int charDiff(string a, string b)
{
    int len1=a.size();
    int len2=b.size();
    if(len1!=len2)
        return -1;
    else
    {
        int d=0;
        for(int i=0;i<len1;i++)
        {
            if(a.at(i)!=b.at(i))
                d++;
        }
        return d;
    }
}
int main()
{
    freopen("429.txt", "r", stdin);
    int n, i, j, t, cas=1;
    char from[12], to[12], temp[12];
    map<string, int> mp;
    scanf("%d", &t);
    while(t--)
    {
        n=i=0;
        while(cin>>A)
        {

            if(A[0]=='*')
                break;
            dic.push_back(A);
            mp[A]=n;
            for(j=0;j<n;j++)
            {
                B=dic.at(j);
                if(charDiff(A, B)==1)
                {

                    g[mp[B]].push_back(mp[A]);
                    g[mp[A]].push_back(mp[B]);
                }
            }
            n++;
        }
        if(cas>1)
            printf("\n");
        getchar();
        while(gets(temp))
        {
            if(temp[0]=='\0')
                break;

            sscanf(temp, "%s %s", from, to);
            source=mp[from];
            dest=mp[to];
            memset(d, 0, sizeof(d));
            bfs();
            printf("%s %s %d\n", from, to, d[dest]);
        }
        for(i=0;i<=n;i++)
        {
            g[i].resize(0);
        }
        dic.resize(0);
        mp.clear();
        cas++;
    }
    return 0;
}
