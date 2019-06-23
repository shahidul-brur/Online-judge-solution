#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 1000000

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll r = floor(log(n)/log(2));
        ll tot = n*(n+1)/2;
        ll tw = pow(2, r+1)-1;
        ll rem = tot - tw;
        ll sum = rem - tw;
        cout << sum << "\n";

    }
    return 0;
}

