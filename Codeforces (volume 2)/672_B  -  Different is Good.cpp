#include<bits/stdc++.h>
using namespace std;
int f[30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char s[100005];
    int len, i;
    cin>>len;
    cin>>s;
    for(i=0;i<len;i++)
    {
        f[s[i] - 'a']++;
    }
    if(len>26)
        cout << "-1\n";
    else
    {
        int cn = 0, z=0;
        for(i=0;i<26;i++)
            if(f[i]>=1)
                cn+=f[i]-1;
            else z++;
        if(z<cn)
            cout << "-1\n";
        else
        {
            cout << cn << "\n";
        }
    }
    return 0;
}

