#include<bits/stdc++.h>
using namespace std;
const int MX = 200005;
int a[105];
int main()
{
    int n, x, y;
    cin>>n;
    for(int i = 0;i<2*n;i++)
    {
        cin>>a[i];
    }
    sort(a, a+2*n);
    if(a[n-1]>=a[n])
        cout << "NO\n";
    else cout << "YES\n";
    return 0;
}
