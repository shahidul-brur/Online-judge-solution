#include<bits/stdc++.h>
using namespace std;
int d[5][15];
//int digit[5][15];
bool vis[14];
int main()
{
    int n, x;
    while(cin>>n)
    {
        memset(d, 0, sizeof d);
        //memset(d, 0, sizeof d);
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=6;j++)
                {
                    cin>>x;
                    d[i][x] = 1;
                    vis[x] = 1;
                    //digit[i][j] = x;
                }
        int cnt = 0;
        for(int i = 1;i<=999;i++)
        {
            if(i<=9)
            {
                if(vis[i]==0)
                    break;
                else
                    cnt++;
                continue;
            }
            if(i<=99)
            {
                bool ok = 0;
                int d1 = i%10;
                int d2 = i/10;
                for(int j= 1;j<=n;j++)
                {
                    for(int k = 1;k<=n;k++)
                    {
                        if(k==j) continue;
                        if((d[k][d1]==1 && d[j][d2]==1) || (d[j][d1]==1 && d[k][d2]==1))
                        {
                            ok = 1;
                            break;
                        }
                    }
                    if(ok==1)
                        break;
                }
                if(ok==1)
                    cnt++;
                else break;
            }
            else
            {
                bool ok = 0;
                int tem = i;
                int d1 = tem%10;
                tem/=10;
                int d2 = tem%10;
                int d3 = tem/10;
                for(int j= 1;j<=n;j++)
                {
                    for(int k = 1;k<=n;k++)
                    {
                        
                        if(k==j) continue;
                        for(int l = 1;l<=n;l++)
                        {
                            if(l==j || l==k)
                                continue;
                            if((d[j][d1]==1 && d[k][d2]==1 && d[l][d3]==1) 
                               || (d[j][d1]==1 && d[k][d3]==1 && d[l][d2]==1)
                               || (d[j][d2]==1 && d[k][d3]==1 && d[l][d1]==1)
                               || (d[j][d2]==1 && d[k][d1]==1 && d[l][d3]==1)
                               || (d[j][d3]==1 && d[k][d1]==1 && d[l][d2]==1)
                               || (d[j][d3]==1 && d[k][d2]==1 && d[l][d1]==1))
                            {
                                ok = 1;
                                break;
                            }
                        }
                        if(ok==1)
                                break;
                    }
                    if(ok==1)
                        break;
                }
                if(ok==1)
                    cnt++;
                else 
                    break;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

