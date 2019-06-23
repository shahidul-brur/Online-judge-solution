#include<bits/stdc++.h>
using namespace std;
int a[100002];
int step[100002][320];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++) cin>>a[i];
    int rt = sqrt(n);
    for(int i=n;i>=1;i--)
    {
        for(int j = 1;j<=rt;j++)
        {
            if(i+a[i]+j>n) step[i][j] = 1;
            else step[i][j] = 1+step[i+a[i]+j][j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int p, k;
        cin>>p>>k;
        if(k<=rt) cout << step[p][k] << "\n";
        else
        {
            int cnt = 1;
            p = p+a[p]+k;
            while(p<=n){
                cnt++;
                p = p+a[p]+k;
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}