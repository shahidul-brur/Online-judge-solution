#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int have[100005], n, m, c[100005], k, i, j, cost;
    while(cin>>n>>m)
    {
        have[0] = 0;
        for(i=1;i<=n;i++)
        {
            cin>>have[i];
        }
        sort(have, have+n+1);
        have[n+1]=1000000000;
        k = cost = 0;
        i = 1;
        while(cost<m && i<=n+1)
        {
            for(j=have[i-1]+1;j<have[i];j++)
            {
                if(cost+j<=m)
                {
                    c[k++] = j;
                    cost+=j;
                    if(cost>=m)
                        break;
                }
                else break;
            }
            i++;
        }
        cout << k << "\n";
        for(i=0;i<k;i++)
            cout << c[i] << " ";
        cout << "\n";
    }
    return 0;
}
