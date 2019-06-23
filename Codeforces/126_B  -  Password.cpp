#include <bits/stdc++.h>
using namespace std;

int Z_algo(string s)
{
    int n = s.length();
    vector<int> z(n);
    z[0] = 0;
    int maxZ = 0;
    for(int i = 1, l = 0, r = 0;i<n;i++)
    {
        if(i<=r) z[i] = min(r-i+1, z[i-l]);
        else z[i] = 0;
        while(z[i]+i<n && s[z[i]]==s[z[i]+i]) ++z[i];
        if(z[i]==n-i && maxZ>=n-i)
            return i;
        if(z[i]+i-1>r) l = i, r = z[i]+i-1;
        maxZ = max(maxZ, z[i]);
    }
    return -1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string s;
    while(cin>>s)
    {
        int pos = Z_algo(s);
        int n = s.length();
        if(pos==-1)
            cout << "Just a legend";
        else 
            for(int i = pos;i<n;i++)
                cout << s[i];
        cout << "\n";
    }
    return 0;
}
