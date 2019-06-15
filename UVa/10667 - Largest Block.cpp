//Accepted

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("10667.txt", "r", stdin);
    int siz, t, occu, r1, c1, r2, c2, grid[105][105], i, j, area, max_area, right, down, k, l, min_right;
    cin>>t;
    while(t--)
    {
        cin>>siz>>occu;

        for(i=1;i<=siz;i++)
        {
            for(j=1;j<=siz;j++)
            {
                grid[i][j]=0;
            }
        }
        for(k=1;k<=occu;k++)
        {
            cin>>r1>>c1>>r2>>c2;
            for(i=r1;i<=r2;i++)
            {
                for(j=c1;j<=c2;j++)
                {
                    grid[i][j]=1;
                }
            }
        }
        max_area=0;
        for(i=1;i<=siz;i++)
        {
            for(j=1;j<=siz;j++)
            {
                down=0;
                min_right=110;
                for(k=i;k<=siz && grid[k][j]==0;k++)
                {
                    down++;
                    right=0;
                    for(l=j;l<=siz && grid[k][l]==0;l++)
                    {
                        right++;
                    }
                    if(right<min_right)
                        min_right=right;
                    area=down*min_right;
                    if(area>max_area)
                        max_area=area;
                }
            }
        }
        cout<<max_area<< '\n';
    }
    return 0;
}
