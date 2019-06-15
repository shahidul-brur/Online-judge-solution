#include<bits/stdc++.h>
using namespace std;
int w[2002], dpMini[2002], dpMaxi[2002], n;

int miniLIS(int i)
{
    if(dpMini[i]!=-1)
        return dpMini[i];
    
    int smaller=0, m = 0;
    for(int j=i+1;j<n;j++)
    {
        if(w[j]<w[i])
        {
            if(dpMini[j]!=-1)
                smaller = dpMini[j];
            else smaller = miniLIS(j);
            m = max(m, smaller);
        }
    }
    
    return dpMini[i] = m + 1;
}
int maxiLIS(int i)
{
    if(dpMaxi[i]!=-1)
        return dpMaxi[i];
    int bigger=0, m = 0;
    for(int j=i+1;j<n;j++)
    {
        if(w[j]>w[i])
        {
            if(dpMaxi[j]!=-1)
                bigger = dpMaxi[j];
            else bigger = maxiLIS(j);
            m = max(m, bigger);
        } 
    }
    
    return dpMaxi[i] = m + 1;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int test, i, mx;
    cin>>test;
    while(test--)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>w[i];
        }
        
        memset(dpMini, -1, sizeof(dpMini));
        memset(dpMaxi, -1, sizeof(dpMaxi));
        
        mx = 0;
        
        
        for(i=0;i<n;i++)
        {
            mx = max(mx, miniLIS(i)+maxiLIS(i)-1);
        }
        
        cout << mx << "\n";
    }
    return 0;
}
