/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
#define pb push_back
bool st[1000005];
bool mark[1000005];
vi prime;
void sieve(int n)
{
    prime.pb(2);
    for(int i=3;i<=n;i+=2)
    {
        if(st[i]==0)
        {
            prime.pb(i);
            for(int j=i+i;j<=n;j+=i)
                st[j] = 1;
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, k, ans, test, j, i, cnt;
    sieve(1000000);
    scanf("%d", &test);
    int sz = prime.size();
    while(test--)
    {
        scanf("%d %d", &n, &k);
        int r = sqrt(n);
        cnt=0;
        memset(mark, 0, sizeof(mark));
        for(i=1;i<=r;i++)
        {
           if(mark[i]==0)
            {
                cnt+= (n/(i*k))/2 ;
                cout << (n/(i*k))/2 << "#\n";
                for(int j=i;j<=r;j*=k)
                    mark[j] = 1;
            }
        }
        cout << n-cnt << "\n";
    }
    return 0;
}
