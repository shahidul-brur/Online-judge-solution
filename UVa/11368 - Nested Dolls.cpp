#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
bool s[20005];
int n, dp[20005];
int Lis(int i)
{
    if(dp[i]!=-1)
        return dp[i];
    int mx = 0;
    for(int j=i+1;j<n;j++)
    {
        if(v[j].first > v[i].first && v[j].second > v[i].second)
        {
            dp[j] = Lis(j);
            mx = max(mx, dp[j]);
        }
    }
    return dp[i] = mx + 1;
}
void cutFrom(int i)
{
    s[i] = true;
    for(int j=i+1;j<n;j++)
    {
        if(s[j]==false && v[j].first > v[i].first && v[j].second > v[i].second && dp[j] == dp[i] - 1)
        {
            s[j] = true;
            cutFrom(j);
            break;
        }
    }
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t, h, w;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>h>>w;
            v.push_back(make_pair(h, w));
            s[i] = false;
            dp[i] = -1;
        }
        sort(v.begin(), v.end());
        
        for(int i=0;i<n;i++)
        {
            dp[i] = Lis(i);
            //cout << "  # " << i << " -> " << v[i].first << ", " << v[i].second << " => " << dp[i] << "\n";
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==false)
            {
                //cout << "from " << i << ": ";
                cnt++;
                s[i] = true;
                cutFrom(i);
                //cout << "\n";
            }
        }
        
        cout << cnt << "\n";
        
        v.clear();
    }
    return 0;
}
