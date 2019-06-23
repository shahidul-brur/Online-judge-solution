#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, x[1005], y[1005], i, k;
    while(cin>>n)
    {
        for(i=0;i<=n;i++)
        {
            cin>>x[i]>>y[i];
        }
        
        k = 0;
        
        for(i=1;i<n;i++)
        {
            if(x[i]==x[i-1] && y[i]>y[i-1])
            {
                if(x[i+1]<x[i] && y[i+1]==y[i])
                    k++;
            }
            else if(x[i]==x[i-1] && y[i]<y[i-1])
            {
                if(x[i+1]>x[i] && y[i+1]==y[i])
                    k++;
            }
            else if(x[i]>x[i-1])
            {
                if(y[i+1]>y[i])
                    k++;
            }
            else if(x[i]<x[i-1])
            {
                if(y[i+1]<y[i])
                    k++;
            }
        }
        cout << k << "\n";
    }
    return 0;
}
