#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, a[1005], b[1005], i, j, cnt;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        sort(a, a+n);
        
        cnt=0;
        for(i=0, j=0;j<n;i++)
        {
            b[j++] = a[i];
            b[j++] = a[n-i-1];
        }
        bool  y=1;
        for(i=1;i<n;i++)
        {
            if((i+1)%2==0 && b[i]<b[i-1])
            {
                y=0;
                break;
            }
            else if((i+1)%2==1 && b[i]>b[i-1])
            {
                y=0;
                break;
            }
        }
        if(y==0)
            cout << "Impossible\n";
        else
        {
            for(i=0;i<n;i++)
                cout << b[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}