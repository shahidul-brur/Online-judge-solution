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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
//             0123456789
const int MX = 100000;
int a[55], sum[55];
int dp[55][2];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, s = 0;
    cin>>n;
    f(i, 1, n) cin>>a[i], s+=a[i];
    sum[n] = a[n];
    for(int i = n-1;i>=1;i--){
        sum[i] = sum[i+1]+a[i];
    }
    dp[n][0] = 0;
    dp[n][1] = a[n];
    for(int i = n-1;i>=1;i--){
        dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
        dp[i][1] = a[i]+(sum[i+1]-max(dp[i+1][0], dp[i+1][1]));
    }
    cout << s - max(dp[1][0], dp[1][1]) << " " << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}

