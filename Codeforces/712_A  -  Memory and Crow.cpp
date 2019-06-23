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
    int a[100005], b[100005];
    cin>>n;
    F(i, 1, n)
    {
        cin>>a[i];
    }
    F(i, 1, n-1)
    {
        b[i] = a[i]+a[i+1];
    }
    b[n] = a[n];
    F(i, 1, n)
    {
        cout << b[i]  << " ";
    }
    cout << "\n";
    return 0;
}

