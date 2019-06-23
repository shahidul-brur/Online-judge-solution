#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char s[200], sl[200], su[200];
    int l, i, low=0, up=0;
    while(cin>>s)
    {
        low=up=0;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                low++;
                sl[i]=s[i];
                su[i] = (char)(s[i] - 'a' + 'A');
            }
            else 
            {
                up++;
                su[i]=s[i];
                sl[i] = (char)(s[i] - 'A' + 'a');
            }
        }
        sl[i]=su[i] = '\0';
        if(low>=up)
            cout << sl << "\n";
        else cout <<  su << "\n";
    }
    return 0;
}