/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
|                                   |
\*=================================*/

#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 100000
typedef vector<int> vi;
typedef vector<vector<ll> > matrix;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

ll M[3][3], a, b, mod;
matrix mul(matrix A, matrix B)
{
    matrix C(3, vector<ll> (3, 0));
    C[1][1] = 0, C[1][2] = 0;
    C[2][1] = 0, C[2][2] = 0;
    F(i, 1, 2) F(j, 1, 2) F(k, 1, 2)
        C[i][j] = (C[i][j]%mod + (A[i][k]*B[k][j])%mod)%mod;
    return C;
}
matrix pw(matrix A, int n)
{
    if(n==1)
        return A;
    if(n%2==1)
        return mul(A, pw(A, n-1));
    matrix x = pw(A, n/2);
    return mul(x, x);
}
ll fib(int n)
{
    if(n==0)
        return a;
    if(n==1)
        return b;
    ll f[4];
    f[1] = b;
    f[2] = a+b;
    
    matrix M(3, vector<ll>(3));
    M[1][1] = 0, M[1][2] = 1;
    M[2][1] = 1, M[2][2] = 1;
    
    M = pw(M, n-1);
    ll res = 0LL;
    F(i, 1, 2)
        res = (res%mod + (M[1][i]*f[i])%mod)%mod;
    return res;
}
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(0);
    ll t, cas, n, m, i, j;
    cin>>t;
    F(cas, 1, t)
    {
        
        cin>>a>>b>>n>>m;
        mod = 1LL;
        F(i, 1, m)
            mod*=10;
        ll ans = fib(n);
        cout << "Case " << cas << ": " <<  ans << "\n";
        
    }
    return 0;
}



