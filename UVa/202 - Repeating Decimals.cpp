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
char s[1005];
int f(int r, int d)
{
    return r/d;
}
void findCycle(int r, int d)
{
    int tor, hare, l, mu, tr, th;
    tr = r;
    th = (r%d)*10;
    while(tor!=hare)
    {
        tor = f(r, d);
        hare = f(f(r, d), d)
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, d, n, a, r;
    while(cin>>n>>d)
    {
        a = n/d;
        r = n%d;

    }
    return 0;
}


