#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    long long p[55], t[55], c, l, r, tl, tr, n, zero = 0;
    while(cin>>n>>c)
    {
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
        }
        
        for(int i=0;i<n;i++)
        {
            cin>>t[i];
        }
        
        l = r= 0;
        tl = tr = 0;
        for(int i=0;i<n;i++)
        {
            tl+=t[i];
            l+=max(zero, p[i]-c*tl);
            
            tr+=t[n-i-1];
            r+=max(zero, p[n-i-1] - tr*c);
        }
        if(l>r)
            cout << "Limak\n";
        else if(r>l)
            cout << "Radewoosh\n";
        else cout << "Tie\n";
    }
    return 0;
}

