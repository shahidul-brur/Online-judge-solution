#include<bits/stdc++.h>
using namespace std;
#define maxn 200005
int cnt[maxn], a[maxn];
vector<int> freq;
int main()
{
    int n, q;
    cin>>n>>q;
    for(int i = 0;i<n;i++) cin>>a[i];
    sort(a, a+n, greater<int>());
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        cnt[l]++;
        cnt[r+1]--;
    }
    for(int i = 1;i<=n;i++) cnt[i]+=cnt[i-1], freq.push_back(cnt[i]);
    sort(freq.begin(), freq.end(), greater<int>());
    long long ans = 0LL;
    for(int i = 0;i<n;i++)
        ans+=1LL*freq[i]*a[i];
    cout << ans;
    return 0;
}
