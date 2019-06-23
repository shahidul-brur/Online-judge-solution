#include<bits/stdc++.h>
using namespace std;

int main()
{
    int b[55], n, i, y;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>b[i];
    sort(b, b+n);
    y=0;
    for(i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            if(b[j]==b[i]+1)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(b[k]==b[j]+1)
                    {
                        y=1;
                        break;
                    }
                }
            }
        }
    }
    if(y)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
