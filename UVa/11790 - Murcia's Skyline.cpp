//WA

#include <bits/stdc++.h>
using namespace std;
vector<int> v, sL, sD;
int inL[1000005], decL[1000005], w[1000005], sLindex[1000005], sDindex[1000005], n, mD, mL;

void LisLds()
{
    for(int i=0;i<n;i++)
    {
        vector<int>::iterator it = lower_bound(sL.begin(), sL.end(), v[i]);
        int pre = 0;
        if(it==sL.end())
        {
            sL.push_back(v[i]);
            sLindex[sL.size()-1] = i;
            if(sL.size()>1)
                pre = inL[sLindex[sL.size()-2]];
            inL[i] = max(inL[i], pre + w[i]);
        }
        else
        {
            *it = v[i];
            if(it - sL.begin()>0)
                pre = inL[sLindex[it - sL.begin() - 1]];
            inL[i] = max(inL[i], pre+w[i]);
        }
        mL = max(mL, inL[i]);
        
        int j = n - i - 1;
        
        vector<int>::iterator it2 = lower_bound(sD.begin(), sD.end(), v[j]);
        pre = 0;
        if(it2==sD.end())
        {
            sD.push_back(v[j]);
            sDindex[sD.size()-1] = j;
            if(sD.size()>1)
                pre = decL[sDindex[sD.size()-2]];
            decL[j] = max(decL[i], pre + w[j]);
        }
        else
        {
            *it2 = v[j];
            if(it2 - sD.begin()>0)
                pre = decL[sDindex[it2 - sD.begin() - 1]];
            decL[i] = max(decL[i], pre+w[j]);
        }
        mD = max(mD, decL[j]);
    }
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
            inL[i]=decL[i] = 0;
        }
        
        mL = mD = 0;
        LisLds();
        cout << "Case " << cas++ << ". ";
        if(mL>=mD)
            cout << "Increasing (" << mL << "). Decreasing (" << mD << ").\n";
        else cout << "Decreasing (" << mD << "). Increasing (" << mL << ").\n";
            
        v.clear();
        sL.clear();
        sD.clear();
    }
    return 0;
}
