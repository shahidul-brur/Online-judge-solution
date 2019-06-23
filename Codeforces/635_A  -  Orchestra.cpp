#include<bits/stdc++.h>
using namespace std;
int h[15][15], n, k, cnt, r, c, x, y, cn;
int main()
{
    int i, j, p, q;
    memset(h, 0, sizeof h);
    cin>>r>>c>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        h[x-1][y-1] = 1;
    }
    cnt = 0;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            for(p=i;p<r;p++)
            {
                for(q=j;q<c;q++)
                {
                    cn = 0;
                    for(x=i;x<=p;x++)
                    {
                        for(y=j;y<=q;y++)
                            {
                                if(h[x][y]==1)
                                    cn++;
                            }
                    }
                    if(cn>=k)
                        cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}
