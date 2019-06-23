#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, m, n, w, h, ans;
    cin>>n>>m>>a;
    w=ceil(m*1.0/a);    // need flagstones towards width

    h=ceil(n*1.0/a);     // need flagstones towards height

    ans=h*w;   // need total flagstones
    cout<<ans<<'\n';
    return 0;
}