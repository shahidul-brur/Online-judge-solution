#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > matrix;
const int dim = 4; // known base terms
const ll MOD = (ll)1e9 + 7;
matrix matrix_mult(matrix A, matrix B)
{
	matrix res(dim, vector<ll>(dim, 0));
	for(int i = 0;i<dim;i++) for(int j = 0;j<dim;j++) for(int k = 0;k<dim;k++)
		res[i][j] = (res[i][j] + (A[i][k] * B[k][j]) % MOD)%MOD;
	return res;
}
matrix matrix_expo(matrix M, int p)
{
	if(p==1) return M;
	matrix cur = matrix_expo(M, p/2);
	cur = matrix_mult(cur, cur);
	if(p&1) cur = matrix_mult(cur, M);
	return cur;
}
ll find_nth_term(int n)
{
	ll T[] = {0, 1, 1, 1};
	if(n==1) return 0;
	matrix F(dim, vector<ll>(dim));
	F = {{0, 1, 1, 1},
		 {1, 0, 1, 1},
		 {1, 1, 0, 1},
		 {1, 1, 1, 0}};
		 
	F = matrix_expo(F, n-1);
	ll ans = 0LL;
	for(int i = 0;i<dim;i++)
		ans = (ans + (F[0][i] * T[i]) % MOD ) % MOD;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout << find_nth_term(n) << "\n";
	return 0;
}

