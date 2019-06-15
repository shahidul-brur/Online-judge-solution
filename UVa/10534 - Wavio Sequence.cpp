#include<bits/stdc++.h>
using namespace std;
#define maxi 10004
int inL[maxi], decL[maxi], n;
vector <int> v, si, sd;

void LIS()
{
    for(int i=0;i<n;i++)
    {
        vector<int>::iterator itr1 = lower_bound(si.begin(), si.end(), v[i]);
        if(itr1 == si.end())
        {
            si.push_back(v[i]);
            inL[i] = si.size();
        }
        else
        {
            *itr1 = v[i];
            inL[i] = itr1 - si.begin()+1;
        }
        
    }
}
void LDS()
{
    for(int i=n-1;i>=0;i--)
    {
        vector<int>::iterator itr2 = lower_bound(sd.begin(), sd.end(), v[i]);
        if(itr2 == sd.end())
        {
            sd.push_back(v[i]);
            decL[i] = sd.size();
        }
        else
        {
            *itr2 = v[i];
            decL[i] = itr2 - sd.begin()+1;
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    while(cin>>n)
    {
        int num;
        for(int i=0;i<n;i++)
        {
            cin>>num;
            v.push_back(num);
        }
        LIS();
        LDS();
        
        int mx = 1;
        
        for(int i=0;i<n;i++)
        {
            cout << decL[i] << " "  << inL[i] << "...\n";
            if(decL[i]>=inL[i]-1)
                mx = max(mx, 2*inL[i] - 1);
        }
        cout << "\n";
        cout << mx << "\n\n";
        v.clear();
        si.clear();
        sd.clear();
    }
    return 0;
}
