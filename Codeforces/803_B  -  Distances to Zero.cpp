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
const int MAX = 200005;
int a[MAX], d[MAX], nxt[MAX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, fs;
    while(cin>>n)
    {
        f(i, 0, n-1) cin>>a[i];
        int p;
        f(i, 0, n-1)
        {
            if(a[i]==0)
            {
                d[i] = 0;
                F(j, i, 0) d[j] = abs(i-j);
                p = i;
                fs = i;
                break;
            }
        }
        f(i, p+1, n-1)
        {
            if(a[i]==0)
            {
                nxt[p] = i;
                d[i] = 0;
                 p = i;
            }
        }
        nxt[p] = n+1;
        F(i, n-1, p) d[i] = abs(i-p);
        
        for(int i = fs;nxt[i]<n;i=nxt[i])
        {
            int x = i, y=nxt[i], cnt = 0;
            while(x<=y)
            {
                d[x++] = cnt;
                d[y--] = cnt;
                cnt++;
            }
        }
        f(i, 0, n-1) cout << d[i] << " ";
        cout << "\n";
    }
    return 0;
}
