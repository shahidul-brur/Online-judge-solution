#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,x,y,z,c=0,mn=2e9;
int main()
{
    string s, u, t;
    cin>>s;
    n = s.size();
    int i = 0;
    multiset<char> m;
    for(int i = 0;i<n;i++) m.insert(s[i]);
    while(1)
    {
        if(t.size()==0 && i==n) break;
        if(t.size()==0)
        {
            t+=s[i];
            m.erase(m.lower_bound(s[i]));
            i++;
        }
        else
        {
            char ch = t.back();
            if(i==n){
                u+=ch;
                t.pop_back();
                continue;
            }
            int ase = 0;
            for(char c = 'a';c<ch;c++){
                if(m.count(c)>0){
                    ase=1;
                    break;
                }
            }
            if(ase){
                t+=s[i];
                m.erase(m.lower_bound(s[i]));
                i++;
            }
            else 
            {
                u+=ch;
                t.pop_back();
            }
        }
    }
    cout << u;
    return 0;
}