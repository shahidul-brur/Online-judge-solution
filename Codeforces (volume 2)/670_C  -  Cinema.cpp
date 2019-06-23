#include<bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, i, ind, ms, ma, see, m;
    while(cin>>n)
    {
        ms=ma=0;
        see = 1;
        for(i=0;i<n;i++)
        {
            cin>>ind;
            mp[ind]++;
        }
        
        cin>>m;
        int mov[m+5];
        for(i=0;i<m;i++)
            cin>>mov[i];
        for(i=0;i<m;i++)
        {
            cin>>ind;
            int sat = mp[mov[i]];
            int alm = mp[ind];
            
            if(sat>ms)
            {
                ms = sat;
                ma = alm;
                see = i+1;
            }
            else if(sat==ms && alm>ma)
            {
                ms = sat;
                ma = alm;
                see = i+1;
            }
        }
        cout << see << "\n";
        
    }
    return 0;
}
