/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MAX = 1000005;
ii num[1005];
bool cmp(ii a, ii b)
{
    if(a.ff>b.ff)
        return 0;
    if(a.ff<b.ff)
        return 1;
    if(a.ff==b.ff)
        return (a.ss>b.ss);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    for(int i = 1;i<=1000;i++)
    {
        int cnt = 0;
        //cout << i << ": ";
        for(int j = 1;j<=i/2;j++)
        {
            if(i%j==0)
            {
                cnt++;
                if(j*j!=i)
                    cnt++;
            }
        }
        //cout << cnt << "\n";
        num[i-1].first = cnt;
        num[i-1].second = i;
    }
    sort(num, num+1000, cmp);
    int t, n;
    cin>>t;
    f(cas, 1, t)
    {
        cin>>n;
        cout << "Case " << cas << ": " << num[n-1].second << "\n";
    }
    return 0;
}

