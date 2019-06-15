//Accepted

#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("10074.txt", "r", stdin);
    int m, n, grid[105][105], i, j, area, max_area, right, down, k, l, min_right;
    while(cin>>m>>n)
    {
        if(m==0 && n==0)
            break;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>grid[i][j];
            }
        }
        max_area=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                down=0;
                min_right=110;
                for(k=i;k<m && grid[k][j]==0;k++)
                {
                    down++;
                    right=0;
                    for(l=j;l<n && grid[k][l]==0;l++)
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
