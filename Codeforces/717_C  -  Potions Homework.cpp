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
    int t, n, i, j;
    ll a[100005];
    cin>>n;
    F(i, 0, n-1)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    ll cnt = 0LL;
    for(i=0, j=n-1;i<n;i++, j--)
    {
        cnt+=(a[j]%10007*a[i]%10007)%10007;
    }
    cout << cnt%10007 << "\n";
    return 0;
}