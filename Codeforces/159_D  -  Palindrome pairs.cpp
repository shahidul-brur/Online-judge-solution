#include<bits/stdc++.h>
using namespace std;
int L[2002];
int R[2002];
int main()
{
    string s;
    cin>>s;
    int n= s.length();
    for(int i = 0;i<n;i++)
    {
        for(int l = i, r = i;l>=0 && r<n && s[l]==s[r];l--, r++)
            R[l]++, L[r]++;
        for(int l = i, r = i+1;l>=0 && r<n && s[l]==s[r];l--, r++)
            R[l]++, L[r]++;
    }
    //for(int i = 1;i<n;i++)
        //L[i]+=L[i-1];
    for(int i = n-2;i>=0;i--)
        R[i]+=R[i+1];
    long long ans = 0;
    for(int i = 0;i<n-1;i++)
        ans+=1LL*L[i]*R[i+1];
    cout << ans << "\n";
    return 0;
}
