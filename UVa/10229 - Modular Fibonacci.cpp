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
int n = 2;

matrix mul(matrix a, matrix b)
{
    matrix c(n+1, vector<ll> (n+1));
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++)
            for(int k = 0;k<n;k++)
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
ll fib(int N)
{
    if(N==0)
        return 0;
    if(N==1)
        return 1;
    vector<ll> A(n+1);
    A[0] = 0;
    A[1] = 1;
    
    matrix M(n+1, vector<ll> (n+1));
    
    M[0][0] = 1; M[0][1] = 1;
    M[1][0] = 1; M[1][1] = 0;
    
    M = power(M, N);
    
    ll ans = 0LL;
    
    for(int i = 0;i<n;i++)
        ans = (ans + M[0][i]*A[i])%mod;
    return ans;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, m;
    while(cin>>N>>m)
    {
        mod = 1LL;
        for(int i = 1;i<=m;i++)
            mod*=2;
        cout << fib(N) << "\n";
    }
    return 0;
}

