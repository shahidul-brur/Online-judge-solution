#include<bits/stdc++.h>
using namespace std;
#define MX 250005;
int n;
vector<int> ans;
multiset<int> st;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    cin>>n;
    for(int i = 1;i<=n*n;i++)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    int mx = *st.rbegin();
    ans.push_back(mx);
    st.erase(st.find(mx));
    int cnt = 1;
    while(cnt<n)
    {
        mx = *st.rbegin();
        ans.push_back(mx);
        st.erase(st.find(mx));
        for(int i = 0;i<cnt;i++)
        {
            int g = __gcd(mx, ans[i]);
            st.erase(st.find(g));
            st.erase(st.find(g));
        }
        cnt++;
    }
    for(int i = 0;i<n;i++)
        cout << ans[i] << " ";
    return 0;
}
