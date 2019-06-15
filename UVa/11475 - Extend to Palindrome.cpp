#include <bits/stdc++.h>
using namespace std;

int Z_algo(string s)
{
    int n = s.length();
    string t = s;
    reverse(t.begin(), t.end());
    s = t + "#" + s;
    int len = s.length();
    vector<int> z(len);
    z[0] = 0;
    for(int i = 1, l = 0, r = 0;i<len;i++){
        if(i<=r) z[i] = min(r-i+1, z[i-l]);
        else z[i] = 0;
        while(z[i]+i<len && s[z[i]]==s[z[i]+i]) ++z[i];
        if(z[i]+i-1>r) l = i, r = z[i]+i-1;
    }
    for(int i = 0;i<n;i++)
        if(z[n+1+i]==n-i)
            return i;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string s;
    while(cin>>s){
        cout << s;
        int p = Z_algo(s);
        for(int i = p-1;i>=0;i--)
            cout << s[i];
        cout << "\n";
    }
    return 0;
}
