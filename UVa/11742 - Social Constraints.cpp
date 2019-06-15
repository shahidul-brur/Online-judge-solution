#include<bits/stdc++.h>
using namespace std;
int mini[12][12], maxi[12][12], n,cnt,a[12];
void check(int at)
{
    if(at==n)
     {   
        cnt++;
        return;
     }
    int j;
    for(int i=0;i<n;i++)  // person i sits at position 
    {
        int flag = 1;
        for(j=0;j<at;j++)
            {
                if(a[j]==i)
                {
                    flag=0;
                    break;
                }
                else if((at-j)>maxi[i][a[j]] || (at-j)<mini[i][a[j]])
                {
                    flag=0;
                    break;
                }
            }
            if(flag==1)
            {
                a[at] = i;
                check(at+1);
            }
        }
}
int main()
{
   //freopen("in.txt", "r", stdin);
    int m, pa, b, c, i, j;
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            break;
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
            {
                mini[i][j] = mini[j][i] = 0;
                maxi[i][j] = 500;
            }
        for(i=1;i<=m;i++)
        {
            cin>>pa>>b>>c;
            if(c<0)
            {
                if(mini[pa][b]==0)
                    mini[pa][b]=mini[b][pa]=abs(c);
                else 
                    mini[pa][b]=mini[b][pa]=max(abs(c), mini[pa][b]);
            }
            else
            {
                if(mini[pa][b]==500)
                    maxi[pa][b] = maxi[b][pa] = c;
                else 
                    maxi[pa][b] = maxi[b][pa] = min(c, maxi[pa][b]);
            }
        }
        cnt = 0;
        for(i=0;i<n;i++)
        {
            a[0]=i;  // person i sits 0'th position
            check(1);
        }
        cout << cnt << "\n";
    }
    return 0;
}