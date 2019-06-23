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

const int MX = 200000;
int a[MX+2];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x, q, l, r, k;
    cin>>n>>k>>q;
    for(int i=1; i<=n;i++)
    {
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }
    for(int i=1; i<=MX;i++)
        a[i]+=a[i-1];
    for(int i=1; i<=MX;i++)
        if(a[i]>=k)
            a[i] = 1;
        else a[i] = 0;
    for(int i=1; i<=MX;i++)
        a[i]+=a[i-1];
    
    for(int i=1; i<=q;i++)
    {
        cin>>l>>r;
        cout << a[r] - a[l-1] << "\n";
    }
    return 0;
}
