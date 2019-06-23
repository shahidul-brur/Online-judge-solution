#include<bits/stdc++.h>
using namespace std;
#define MX 100002
int a[MX], lef[MX], rgt[MX];
int main()
{
//    freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while(cin>>n>>m)
    {
        for(int i = 1;i<=n;i++)
        {
            cin>>a[i];
//            cout << a[i] << " ";
            if(i==1 || a[i]>a[i-1]) lef[i] = i;
            else lef[i] = lef[i-1];
        }
//        cout << "\n";
        for(int i = n;i>=1;i--)
        {
            if(i==n || a[i]>a[i+1]) rgt[i] = i;
            else rgt[i] = rgt[i+1];
        }
//        for(int i = 1;i<=n;i++)
//            cout << i << ": " << lef[i] << " " << rgt[i] << "\n";
        for(int i = 1;i<=m;i++)
        {
            int l, r;
            cin>>l>>r;
//            cout << l << " -- " << r << ": ";
            if(l==r || rgt[l]>=lef[r])
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}
