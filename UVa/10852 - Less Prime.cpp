//Accepted

#include<bits/stdc++.h>
using namespace std;
bool st[32010];
vector<int> prime, seq[200];
int sz, s;
void sieve(int n)
{
    prime.push_back(2);
    for(int i=3;i<=n;i+=2)
    {
        if(st[i]==0)
        {
            prime.push_back(i);
            for(int j=i+i;j<=n;j+=i) st[j]=1;
        }
    }
    sz=prime.size();
}

int main()
{
    sieve(10005);
    int n, t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mx = -1, ans;
        for(int i=0;i<sz && prime[i]<=n;i++)
        {
            if(n%prime[i]>mx)
            {
                mx = n%prime[i];
                ans = prime[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

