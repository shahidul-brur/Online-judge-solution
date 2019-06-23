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
const int MX = 100000;
const int MOD = 1000000007;
const int INF = (int)1e9;
int tree[2*(1<<17)+10];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    n = 1<<n;
    f(i, n, 2*n-1)
    {
        cin>>tree[i];
    }
    
    int orr = 0;
    F(i, n-1, 1)
    {
        if(!(i & (i+1)))
            orr = 1 - orr;
        if(orr)
            tree[i] = tree[i<<1] | tree[(i<<1) | 1];
        else tree[i] = tree[i<<1] ^ tree[(i<<1) | 1];
    }
    
    f(i, 1, m)
    {
        int p, v;
        cin>>p>>v;
        --p;
        orr = 1;
        for(tree[p+=n] = v;p>1;p>>=1)
        {
            if(orr)
                tree[p>>1] = tree[p] | tree[p^1];
            else tree[p>>1] = tree[p] ^ tree[p^1];
            orr = 1 - orr;
        }
        cout << tree[1] << "\n";
    }
    return 0;
}


