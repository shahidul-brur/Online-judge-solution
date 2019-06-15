/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
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
int sum[1005][1005];
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, cas=1;
    while(cin>>n>>m)
    {
        sum[0][0] = 0;
        f(i, 1, n) 
        {
            int col_sum = 0;
            f(j, 1, n)
            {
                int x;
                cin>>x;
                col_sum+=x;
                sum[i][j] = sum[i-1][j] + col_sum;
            }
        }
        if(cas>1)
            cout << "\n";
        ll tot = 0LL;
        f(i, 1, n-m+1) f(j, 1, n-m+1)
        {
            int x = sum[i+m-1][j+m-1] - sum[i-1][j+m-1] - sum[i+m-1][j-1] + sum[i-1][j-1];
            tot+=x;
            cout << x << "\n";
        }
        cout << tot << "\n";
        cas++;
    }
    return 0;
}

