#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a, i, total, t;
    cin>>t;
    while(t-->0)
    {
        cin>>a;
        if((180-a)>0 && 360%(180-a)==0)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
