#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MX = 100005;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    double r, d, cx, cy, rd;
    int n, cnt;
    while(cin>>r>>d)
    {
        cin>>n;
        cnt = 0;
        f(i, 1, n)
        {
            cin>>cx>>cy>>rd;
            double cd = sqrt(cx*cx + cy*cy);
            //cout << cd << " " << r*r << " " << (r-d)*(r-d) << " .\n";
            if(cd - rd >= r-d && cd + rd<= r)
            {
               //cout << i << " #\n";
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}