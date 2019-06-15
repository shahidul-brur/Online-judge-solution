
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define INF 1<<28
#define null NULL
#define pb(x) push_back(x)
#define PI 2*acos(0.0)
#define mod 10000000000007

typedef pair<int, int> pii;
long long npr(long long n, long long r)
{
	long long i, j, p = 1, q = 1;
	for (i = n; i >= n - r + 1; i--)
	{
		p = ((p%mod)*(i%mod)) % mod;
	}
	return p;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	long long test, cas, L, M, N, sum;
	scanf("%lld", &test);
	for (cas = 1; cas <= test; cas++)
	{
		scanf("%lld %lld %lld", &L, &M, &N);
		long long pre = npr(L*L, M) % mod;
		sum = pre;
		for (long i = M+1; i<=N; i++)
		{
			sum = (sum%mod + (pre*((L*L-i+1)%mod) )% mod)%mod;
			pre = (pre*((L*L - i+1) % mod)) % mod;
		}
		printf("Case %lld: %lld\n", cas, sum);
	}
	return 0;
}


