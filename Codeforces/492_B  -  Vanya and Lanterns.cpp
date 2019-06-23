#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, l;
    int a[1005];
    cin>>n>>l;

    for(int i =0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    int mini = max(a[0]*2, (l-a[n-1])*2);
    for(int i = 1;i<n;i++)
        mini = max(mini, a[i]-a[i-1]);
    cout << fixed;
    cout << setprecision(10);
    cout << (double)mini/2.0 << "\n";
    return 0;
}
