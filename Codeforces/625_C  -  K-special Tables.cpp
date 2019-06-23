#include<bits/stdc++.h>
using namespace std;
int a[505][505];
int main()
{
    int n, k, i, j, r, c;
    while(cin>>n>>k)
    {
        int x = 1;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<k;j++)
                a[i][j] = x++;
        }

        for(i=1;i<=n;i++)
        {
            for(j=k;j<=n;j++)
                a[i][j] = x++;
        }
        int sum = 0;
        for(i=1;i<=n;i++)
            sum+=a[i][k];
        cout << sum << "\n";
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout << a[i][j] << " ";
            cout << "\n";

        }
        cout << "\n";
    }
    return 0;
}
