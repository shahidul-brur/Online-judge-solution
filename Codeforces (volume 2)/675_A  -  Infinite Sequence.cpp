#include<bits/stdc++.h>
using namespace std;
#define pb push_back()
#define ll long long
#define vector<int> vi


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll a, b, c;
    while(cin>>a>>b>>c)
    {
        if(c==0)
        {
            if(a==b)
                cout << "YES\n";
            else cout << "NO\n";
        }
        else
        {
            if(abs(b-a)%c!=0)
                cout << "NO\n";
            else if((b-a)/c + 1 <=0)
                cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}
