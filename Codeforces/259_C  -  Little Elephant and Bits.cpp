#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    bool f = 0;
    for(int i = 0;i<l-1;i++)
    {
        if(s[i]=='0' && f == 0)
            f = 1;
        else cout << s[i];
    }
    if(f)
        cout << s[l-1];
    cout << "\n";
    return 0;
}

