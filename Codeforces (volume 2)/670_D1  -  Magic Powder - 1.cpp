#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k, need[1005], i, j, have[1005], mn, tmp;
    
    cin>>n>>k;
    vector<pair<int, int> > cnt; 
    
    for(i=0;i<n;i++)
    {
        cin>>need[i];
    }
    mn = 1000000000;
    for(i=0;i<n;i++)
    {
        cin>>have[i];
        
        int now = have[i]/need[i];
        cnt.push_back(make_pair(now, i));
        have[i] = have[i] % need[i];
        mn = min(mn, now);
        //cout << have[i] << "\n";
    }
    sort(cnt.begin(), cnt.end());
    
    while(k>0)
    {
        tmp = 1000000000;
        //cout << k << "\n";
        for(i=0;i<n && k>0;i++)
        {
            if(have[cnt[i].second]<need[cnt[i].second] && k>=(need[cnt[i].second] - have[cnt[i].second]) && cnt[i].first==mn)
            {
                cnt[i].first++;
                k-=(need[cnt[i].second] - have[cnt[i].second]);
                have[cnt[i].second] = 0;
            }
            tmp = min(tmp, cnt[i].first);
        }
        sort(cnt.begin(), cnt.end());
        
        if(mn==tmp)
            break;
        mn = tmp;
    }
    mn = 1000000000;
    for(i=0;i<n;i++)
    {
        
        mn = min(mn, cnt[i].first);
    }
    cout << mn << "\n";
    return 0;
}

