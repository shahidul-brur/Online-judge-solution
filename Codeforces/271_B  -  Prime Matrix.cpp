#include<bits/stdc++.h>
using namespace std;
#define MAX 100008
bool prime[MAX];
int p[MAX];

void sieve()
{
    prime[0] = prime[1] = 1;
    for(int i = 4;i<=MAX;i+=2) prime[i] = 1;
    int sq = sqrt(MAX);
    for(int i = 3;i<=MAX;i+=2)
    {
        if(i<=sq && !prime[i])
        {
            for(int j = i*i;j<=MAX;j+=2*i)
                prime[j] = 1;
        }
    }
    int cur = 100003;
    for(int i = 100000;i>=0;i--)
    {
        if(!prime[i])
            cur = i;
        p[i] = cur - i;
    }
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    sieve();
    int n, m;
    int g[505][505];
    while(cin>>n>>m)
    {
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=m;j++)
                cin>>g[i][j], g[i][j] = p[g[i][j]];
        int mini = 10000000;
        for(int i = 1;i<=n;i++)
        {
            int sum = 0;
            for(int j = 1;j<=m;j++)
                sum+=g[i][j];
            mini = min(mini, sum);
        }
        
        for(int i = 1;i<=m;i++)
        {
            int sum = 0;
            for(int j = 1;j<=n;j++)
                sum+=g[j][i];
            mini = min(mini, sum);
        }
        cout << mini << "\n";
    }
    return 0;
}