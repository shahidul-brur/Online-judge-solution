#include<bits/stdc++.h>
using namespace std;
int  v[100005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdin);
    int n, i, j, inf, d[100005], p;
    string s;
    while(cin>>n)
    {
        cin>>s;
        for(i=0;i<n;i++)
            cin>>d[i];
        p = 1;
        inf = 1;
        for(i=0;i<n;)
        {
            if(v[i]==1)
                break;
            if(s[i]=='<')
                p-=d[i];
            else p+=d[i];
            v[i] = 1;
            //cout << "  # " << i << ", " << p << "\n";
            if(p<=0 || p>n)
            {
                inf = 0;
                break;
            }
            i = p-1;
        }
        if(inf==0)
            cout << "FINITE\n";
        else cout << "INFINITE\n";
    }
    return 0;
}
