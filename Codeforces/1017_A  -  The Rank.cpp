#include<bits/stdc++.h>
using namespace std;
pair<int, int> p[1005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        p[i].first = -(a+b+c+d);
        p[i].second = i;
    }
    sort(p, p+n);
    int ans = 1;
    for(int i = 0;i<n;i++)
    {
        if(p[i].second==0)
        {
            ans = i+1;
            break;
        }
    }
    cout << ans;
    return 0;
}
