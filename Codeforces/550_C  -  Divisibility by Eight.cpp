#include<bits/stdc++.h>
using namespace std;
string s;
int len;
bool isSubsequence(int n)
{
    ostringstream ss;
    ss<<n;
    string t = ss.str();
    int l = t.length();
    int i=0, j;
    for(j = 0;j<len && i<l;j++)
    {
        if(s[j]==t[i])
            i++;
    }
    return (i==l);
}
int main()
{
    while(cin>>s)
    {
        //cout << s << ": ";
        len = s.length();
        bool yes = 0;
        for(int i = 0;i<=999 && yes==0;i+=8)
        {
            if(isSubsequence(i))
            {
                cout << "YES\n";
                cout << i << "\n";
                yes = 1;
                break;
            }
        }
        if(!yes) cout << "NO\n";
    }
    return 0;
}
