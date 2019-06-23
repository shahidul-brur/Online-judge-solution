#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef vector<vector<int> > matrix;
const int MOD = 1000000007;

matrix mul(matrix A, matrix B){
    int K = A[0].size();
    matrix C(K, vector<int>(K, 0));
    REP(i, K) REP(j, K) REP(k, K)
        C[i][j] = (C[i][j] + 1LL*A[i][k] * B[k][j]%(MOD-1)) % (MOD-1);
    return C;
}

matrix pow(matrix A, ll p){
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

int term_c(ll N)
{
    vector<int> F(5, 0);
    F[3] = 2;
    F[4] = 2;
    matrix T(5, vector<int>(5, 0));
    T[0][1] = 1;
    T[1][2] = 1;
    T[2][0] = 1, T[2][1] = 1,T[2][2] = 1,T[2][3] = 1;
    T[3][3] = 1, T[3][4] = 1;
    T[4][4] = 1;
    T = pow(T, N-1);
    int res = 0;
    REP(i, 5)
        res = (res + 1LL*T[0][i] * F[i]%(MOD-1)) % (MOD-1);
    return res;
}

int mPow(int a, int n) {
	int r = 1;
	while (n > 0) {
		if (n %2==1) {
			r = 1LL*r * a % MOD;
		}
		a = 1LL*a * a % MOD;
		n /= 2;
	}
	return r;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    int c, f1, f2, f3;
    cin>>n>>f1>>f2>>f3>>c;
    
    matrix T(3, vector<int>(3, 0));
    T[0][1] = 1;
    T[1][2] = 1;
    T[2][0] = 1, T[2][1] = 1, T[2][2] = 1;
    T = pow(T, n-1);
    
    int p1 = T[0][0], p2 = T[0][1], p3 = T[0][2];
    
    int pc = term_c(n);
    
    f1 = mPow(f1, p1);
    f2 = mPow(f2, p2);
    f3 = mPow(f3, p3);
    c = mPow(c, pc);
    
    int ans = 1LL*f1*f2 % MOD;
    ans = 1LL*ans*f3 % MOD;
    ans = 1LL*ans*c % MOD;
//    cout << p1 << " ";
//    cout << p2 << " ";
//    cout << p3 << " ";
//    cout << c << " = ";
    cout << ans;
    return 0;
}