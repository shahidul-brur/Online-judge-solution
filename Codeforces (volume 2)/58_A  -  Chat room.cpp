#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char s[200], sl[200], su[200];
    int l, i, h, e, ll, L, o;
    while(cin>>s)
    {
        h=e=ll=L=o=0;
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            if(s[i]=='h')
            {
                h=1;
                //cout << "h, ";
                break;
            }
        }
        
        for(i=i+1;i<l;i++)
        {
            if(s[i]=='e')
            {
                e=1;
                //cout << "e, ";
                break;
            }
        }
        
        for(i=i+1;i<l;i++)
        {
            if(s[i]=='l')
            {
                ll=1;
                //cout << "l, ";
                break;
            }
        }
        
        for(i=i+1;i<l;i++)
        {
            if(s[i]=='l')
            {
                L=1;
                //cout << "L, ";
                break;
            }
        }
        
        for(i=i+1;i<l;i++)
        {
            if(s[i]=='o')
            {
                o=1;
                //cout << "o, ";
                break;
            }
        }
        //cout << h+e+ll+L+o << "\n";
        if(h+e+ll+L+o==5)
            cout <<"YES\n";
        else cout <<"NO\n";
    }
    return 0;
}