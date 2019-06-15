//Accepted

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, cas=1, t, i, j, area, max_area, right, down, k, l, min_right;
    char grid[105][105];
    cin>>t;
    getchar();
    gets(grid[0]);
    while(t--)
    {
        n=0;
        while(gets(grid[n]))
        {
            if(grid[n][0]=='\0')
                break;
            n++;
        }

        max_area=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                down=0;
                min_right=110;
                for(k=i;k<n && grid[k][j]=='1';k++)
                {
                    down++;
                    right=0;
                    for(l=j;l<n && grid[k][l]=='1';l++)
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
        if(cas>1)
            printf("\n");
        cout<<max_area<< '\n';
        cas++;
    }
    return 0;
}
