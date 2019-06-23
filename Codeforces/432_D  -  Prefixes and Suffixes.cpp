#include <bits/stdc++.h>
using namespace std;
int total = 0;
vector<int> ans;
int cnt[100005];
void Z_algo(string s)
{
    int n = s.length();
    vector<int> z(n);
    ans.push_back(n);
    cnt[n] = 1;
    z[0] = 0;
    for(int i = 1, l = 0, r = 0;i<n;i++)
    {
        if(i<=r) z[i] = min(r-i+1, z[i-l]);
        else z[i] = 0;
        while(z[i]+i<n && s[z[i]]==s[z[i]+i]) ++z[i];
        if(z[i]==n-i)
            ans.push_back(n-i);
        if(z[i]+i-1>r) l = i, r = z[i]+i-1;
        cnt[z[i]]+=1;
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string s;
    while(cin>>s)
    {
        Z_algo(s);
        int n = s.length();
        int tot = ans.size();
        for(int i = n-1;i>=1;i--)
            cnt[i]+=cnt[i+1];
        cout << tot << "\n";
        for(int i = tot-1;i>=0;i--)
            cout << ans[i] << " " << cnt[ans[i]] << "\n";
    }
    return 0;
}

