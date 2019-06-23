#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t, cas;
    ll a, b, ans;
    cin>>t;
    for(cas=1;cas<=t;cas++)
    {
        cin>>a>>b;
        ll p = ((a-1)/3)*2;
        
        if((a-1)%3==2)
            p++;
            
        ll q = (b/3)*2;
        
        if(b%3==2)
            q++;
        ans = q-p;
        cout << "Case " << cas << ": " << ans << "\n";
    }
    return 0;
}
