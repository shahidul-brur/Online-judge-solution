//Accepted

#include <bits/stdc++.h>
using namespace std;
vector<int> v, sL, sD;
int inL[1000005], decL[1000005], w[1000005], n, mD, mL;

int Lis(int i)
{
    if(inL[i]!=-1 || w[i]<0)
        return inL[i];
    int mx = 0, wid = 0;
    for(int j = i+1;j<n;j++)
    {
        if(v[j]>v[i] && w[j]>=0)
        {
            if(inL[j]!=-1)
                wid = inL[j];
            else wid = Lis(j);
            mx = max(mx, wid);
        }
    }
    return inL[i] = mx + w[i];
}
int Lds(int i)
{
    if(decL[i]!=-1)
        return decL[i];
    int mx = 0, wid = 0;
    for(int j = i+1;j<n;j++)
    {
        if(v[j]<v[i] && w[j]>=0)
        {
            if(decL[j]!=-1)
                wid = decL[j];
            else wid = Lds(j);
            mx = max(mx, wid);
        }
    }
    return decL[i] = mx + w[i];
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t, cas=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int h;
            cin>>h;
            v.push_back(h);
        }
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
            inL[i]=decL[i] = -1;
        }
        
        mL = mD = 0;
        for(int i=0;i<n;i++)
        {
            if(w[i]>=0)
            {
                mL = max(mL, Lis(i));
                mD = max(mD, Lds(i));
            }
        }
        cout << "Case " << cas++ << ". ";
        if(mL>=mD)
            cout << "Increasing (" << mL << "). Decreasing (" << mD << ").\n";
        else cout << "Decreasing (" << mD << "). Increasing (" << mL << ").\n";
            
        v.clear();
    }
    return 0;
}
