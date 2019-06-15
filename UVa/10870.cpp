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
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define inf             1e9
const int MAX = 10005;
typedef vector<vector<ll> > matrix;
ll mod;
int d;
ll a[20], f[20];
matrix mul(matrix a, matrix b)
{
    matrix c(d+2, vector<ll> (d+2));
    for(int i = 1;i<=d;i++)
        for(int j = 1;j<=d;j++)
            for(int k = 1;k<=d;k++)
                c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod;
    return c;
}
matrix power(matrix a, int p)
{
    if(p==1)
        return a;
    if(p%2==1)
        return mul(a, power(a, p-1));
    matrix x = power(a, p/2);
    return mul(x, x);
}
ll fib(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    
    matrix M(d+2, vector<ll> (d+2));
    
    for(int i = 1;i<=d;i++)
        M[1][i] = a[i];
    
    for(int i = 2;i<=d;i++)
        for(int j = 1;j<=d;j++)
            if(j==i-1)
                M[i][j] = 1;
            else M[i][j] = 0;
    
    M = power(M, n-d);
    
    ll ans = 0LL;
    
    for(int i = 1;i<=d;i++)
        ans = (ans + M[1][i]*f[i])%mod;
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>d>>n>>mod)
    {
        if(d==0 && n==0 && mod ==0 )
            break;
        for(int i = 1;i<=d;i++)
            cin>>a[i], a[i]%=mod;
        for(int i = 1;i<=d;i++)
            cin>>f[d-i+1], f[i]%=mod;
        cout << fib(n) << "\n";
    }
    return 0;
}
