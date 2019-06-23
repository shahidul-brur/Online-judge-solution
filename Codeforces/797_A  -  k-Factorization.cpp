#include<bits/stdc++.h>
using namespace std;
int n,i,j,k,x,y,z,c=0,mn=2e9;
int main()
{
    cin>>n>>k;
    int nn = n;
    vector<int>v;
    for(int i=2; i<=sqrt(n); i++)
    {
        while(n%i==0)
        {
            v.push_back(i);
            n/=i;
        }
    }
    if(n>1) v.push_back(n);
    z=v.size();
    if(k>z) cout << -1;
    else
    {
        int m = 1;
        for(i=0; i<k-1; i++)
        {
            cout<<v[i]<<" ";
            m*=v[i];
        }
        cout << nn/m;
    }
}