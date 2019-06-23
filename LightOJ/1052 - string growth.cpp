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
#define mod 1000000007
#define N 100000
typedef vector<int> vi;
typedef vector<vector<ll> > matrix;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

ll M[3][3];
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
    if(n<=1)
        return (ll)n;
    ll f[4];
    f[1] = 1;
    f[2] = 1;
    
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
    ll t, cas, n, m, i, j, k, x, y, a, b;
    cin>>t;
    F(cas, 1, t)
    {
        cin>>n;
        
        cin>>x>>m>>y>>k;
        
        ll dx = fib(n)*fib(m+1) - fib(m)*fib(n+1);
        ll dy = fib(m)*fib(n+1) - fib(n)*fib(m+1);
        cout << "Case " << cas << ": ";
        if(dx==0 || dy==0)
            cout << "Impossible\n";
        else
        {
            
            ll upx = (fib(m+1)*x - fib(n+1)*y);
            ll upy = ((fib(m)*x - fib(n)*y));
            a = upx/dx;
            b = upy/dy;
            
            ll ans = (fib(k)*a %mod + fib(k+1)*b %mod)%mod;
            if(a<0 || b<0 || upx%dx!=0 || upy%dy!=0)
                cout << "Impossible\n";
            else cout << ans << "\n";
        }
    }
    return 0;
}


