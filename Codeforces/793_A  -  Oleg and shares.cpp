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
const int MAX = 100005;
ll ara[MAX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll n, k;
    while(cin>>n>>k)
    {
        bool pos = 1;
        ll mini = 2000000009;
        f(i, 0, n-1)
        {
            cin>>ara[i];
            mini = min(ara[i], mini);
        }
        ll cnt = 0LL;
        f(i, 0, n-1)
        {
            
            if((ara[i] - mini)%k!=0)
            {
                pos=0;
                break;
            }
            cnt+=(ara[i] - mini)/k;
        }
        if(pos==0)
            cout << "-1\n";
        else cout << cnt << "\n";
    }
    return 0;
}

