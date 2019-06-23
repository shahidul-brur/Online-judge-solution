#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int l;
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]!='a' && s[i]!='e' && s[i]!='o' && s[i]!='u' && s[i]!='i' && s[i]!='y'  && s[i]!='A' && s[i]!='E' && s[i]!='O' && s[i]!='I' && s[i]!='U' && s[i]!='Y')
        {
            cout << ".";
            
            if(s[i]>='A' && s[i]<='Z')
                cout << (char((s[i] - 'A') + 'a'));
            else cout << s[i];
        }
    }
    return 0;
}
