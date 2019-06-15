#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s, tmp;
    int f[28], i, j, L, mx;
    while(cin>>s)
    {
        if(s[0]=='#')
            break;
        memset(f, 0, sizeof(f));
        L = s.length();
        mx = 0;
        for(i=0;i<L;i++)
        {
            f[s[i] - 'a']++;
        }
        for(i=0;i<26;i++)
            if(f[i]%2==1)
                mx = i;
        for(i=0;i<mx;i++)
        {
            if(f[i]%2==1)
            {
                cout<<(char)(i+'a');
            }
        }
        cout << "\n";
    }
    return 0;
}
