#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, j, b, g, r, mx;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        r=g=b=0;
        mx = 0;
        for(j=0;j<n;j++)
        {
            if(s[j]=='B')
            	b++;
           
            else if(s[j]=='G')
                g++;
            else r++;
        }
        
        mx = max(mx, r);
        mx = max(mx, b);
        mx = max(mx, g);
        
        cout << n - mx << "\n";
    }
    return 0;
}
