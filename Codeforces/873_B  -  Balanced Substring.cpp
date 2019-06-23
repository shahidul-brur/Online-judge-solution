#include<bits/stdc++.h>
using namespace std;
int o[400005];
int z[400005];
vector<int> diff[400005];
//int bs(int idx)
//{
//    int d = z[i-1] - o[i-1];
//    int l = i+1, r = n, ret = 0;
//    while(l<=r)
//    {
//        int mid = (l+r)/2;
//        if(z[mid]-o[mid]==d)
//        {
//            ret = max(ret, mid - i+1);
//            l = mid+1;
//        }
//        else if()
//    }
//    return ret;
//}
int main()
{
    int n, ans;
    string s;
    cin>>n>>s;
    s = '#' + s;
    for(int i = 1;i<=n;i++)
    {
        z[i] = z[i-1];
        o[i] = o[i-1];
        if(s[i]=='0') o[i]++;
        else z[i]++;
        int d = o[i] - z[i]+n;
        diff[d].push_back(i);
    }
    for(int i = 0;i<=2*n;i++)
        if(diff[i].size()>0)
            sort(diff[i].begin(), diff[i].end());

    ans = 0;
    for(int i = 1;i<=n;i++)
    {
        int d = o[i-1] - z[i-1]+n;
        if(diff[d].size()>0 && diff[d].back()>i)
            ans = max(ans, diff[d].back() - i+1);
    }
    cout << ans << "\n";
    return 0;
}

