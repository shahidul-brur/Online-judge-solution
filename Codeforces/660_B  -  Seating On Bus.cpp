#include<bits/stdc++.h>
using namespace std;
int p[105][6];
int main()
{
    //freopen("in.txt", "r", stdin);
    
    int n, m, now, i;
    cin>>n>>m;
    now=1;
    for(i=1;i<=n && now<=m;i++)
    {
        p[i][1] = now++;
        if(now>m)
            break;
        p[i][4] = now++;
    }
    
    for(i=1;i<=n && now<=m;i++)
    {
        p[i][2] = now++;
        if(now>m)
            break;
        p[i][3] = now++;
    }
    
    for(i=1;i<=n;i++)
    {
        if(p[i][2]!=0)
            cout << p[i][2] << " ";
        if(p[i][1]!=0)
            cout << p[i][1] << " ";
        if(p[i][3]!=0)
            cout << p[i][3] << " ";
        if(p[i][4]!=0)
            cout << p[i][4] << " ";
    }
    return 0;
}
