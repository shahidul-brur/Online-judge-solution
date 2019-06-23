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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = (int)1e6;
const int MOD = 1000000007;
const int INF = (int)1e9;
int BIT[MX+5], n;
pair<int, int> ara[MX+5];
int arr[MX+5], big[MX+5];
int ask(int pos)
{
    int sum = 0;
    while(pos>0)
        sum+=BIT[pos], pos-=(pos&-pos);
    return sum;
}
void update(int pos, int val)
{
    while(pos<=n)
        BIT[pos]+=val, pos+=(pos&-pos);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ara[i].ff, ara[i].ss = i;
    sort(ara+1, ara+n+1);
    for(int i = 1;i<=n;i++)
        arr[ara[i].ss] = i;
    for(int i=1;i<=n;i++)
    {
        big[i] = i-1 - ask(arr[i] - 1);
        update(arr[i], 1);
    }
    ll ans = 0;
    for(int i=2;i<n;i++)
    {
        int small = arr[i]-1 - (i-1-big[i]);
        ans+=1LL*small*big[i];
    }
    cout << ans << "\n";
    return 0;
}

