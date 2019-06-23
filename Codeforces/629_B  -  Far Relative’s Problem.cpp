#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, pair<int, int> > > f;
    int n, i, cnt, mx=-1, M, F, a, b, c=1000, d=-1, id;
    char t[5];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>t>>a>>b;
        c= min(c, a);
        d= max(d, b);
        if(t[0]=='F')
            id=2;
        else id=1;
        f.push_back(make_pair(id, make_pair(a, b)));
    }
    for(i=c;i<=d;i++)
    {
        M=F=0;
        for(int j=0;j<n;j++)
        {
            if(f[j].second.first <= i && f[j].second.second>=i)
            {
                if(f[j].first==1)
                    M++;
                else F++;
            }
        }
        cnt=min(M, F);
        mx = max(mx, cnt);
    }
    cout << mx*2 << "\n";
    return 0;
}
