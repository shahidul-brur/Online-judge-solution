#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, l, c, d, p, nl, np;
    while(cin>>n>>k>>l>>c>>d>>p>>nl>>np)
    {
        int drink = (k*l)/nl;
        int lime = c*d;
        int salt = p/np;

        int ans = min(drink, min(lime, salt))/n;
        cout << ans << "\n";
    }
    return 0;
}