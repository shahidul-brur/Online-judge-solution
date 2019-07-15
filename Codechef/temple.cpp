/**************************************************************************************************************
   *  Md. Abdulla Al Mamun (Nayon)
   *  ID: 1306001
   *  Session: 2013-2014
   *  Department of Computer Science and Engineering
   *  Begum Rokeya University, Rangpur (BRUR)
***************************************************************************************************************/
#include <bits/stdc++.h>

using namespace std;

#define PI acos(-1.0)
#define EPS 1e-9
#define INF 1 << 28
#define sq(a) ((a) * (a))
#define toRad(a) ((a)*(PI)/180)
#define toDeg(a) ((a)*180/(PI))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp(a, b) make_pair(a, b)
#define endl '\n'
#define MAX 100005
#define MOD 1000000007
#define what_is(x) cerr << #x << " is " << x << endl;
#define setbitj(n, j) (n |= (1 << j))
#define isbitjOn(n, j) (((n & (1 << j)) > 0) ? 1 : 0)

inline bool isEq(double a, double b){ return abs(a - b) < EPS; }

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

//#define isValid(a, b) (a >= 0 && a < b)
//int dr[]  =  {0, -1, -1, -1,  0,  1, 1, 1};
//int dc[]  =  {1,  1,  0, -1, -1, -1, 0, 1};

int main(int argc, char* argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, araIn[MAX+5], araMine[MAX+5];
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> araIn[i];
		int n1 = (n+1)/2;
		for(int i = 1; i <= n1; i++){
			araMine[i] = i;
		}
		for(int i = n1+1, j = n/2; i <= n; i++, j--)
			araMine[i] = j;

		int ops1 = 0;
		for(int i = 1; i <= n; i++){
			ops1 += abs(araIn[i] - araMine[i]);
		}
		int ops2 = 0;
		for(int i = 1; i <= n; i++){
			ops2 += abs(araIn[i] - araMine[n-i+1]);
		}
		cout << min(ops1, ops2) << endl;
	}
	return 0;
}
