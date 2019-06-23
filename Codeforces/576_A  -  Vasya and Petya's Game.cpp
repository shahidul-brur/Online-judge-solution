#include <bits/stdc++.h>
using namespace std;
bool del[1005];
vector<int> p;
void sieve()
{
    p.push_back(2);
    for(int i = 3;i<=1000;i+=2)
    {
        if(del[i]) continue;
        
        p.push_back(i);
        for(int j = i+i;j<=1000;j+=i)
            del[j] = 1;
    }
}
int main()
{
    int n, s;
    sieve();
    s = p.size();
    while(cin>>n)
    {
        vector<int> ans;
        for(int i = 0;i<s && p[i]<=n;i++)
        {
            int x = p[i];
            while(x<=n)
            {
                ans.push_back(x);
                x*=p[i];
            }
        }
        int a = ans.size();
        cout << a << "\n";
        for(int i = 0;i<a;i++)
        {
            if(i>0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
        ans.clear();
    }
    return 0;
}
