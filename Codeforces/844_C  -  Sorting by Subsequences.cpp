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
int a[MX];
ii b[MX];
vi seq[MX];
bool vis[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    f(i, 1, n)
    {
        cin>>a[i];
        b[i-1].ff = a[i];
        b[i-1].ss = i;
    }
    sort(b, b+n);
    f(i, 0, n-1)
    {
        a[b[i].ss] = i+1;
    }
    int k = 0;
    f(i, 1, n)
    {
        if(vis[i])
            continue;
        if(a[i]==i)
        {
            seq[++k].pb(i);
            vis[i] = 1;
            continue;
        }
        ++k;
        int j = i;
        while(1)
        {
            seq[k].pb(j);
            vis[j] = 1;
            j = a[j];
            if(vis[j])
                break;
        }
    }
    
    cout << k << "\n";
    f(i, 1, k)
    {
        int s = seq[i].size();
        cout << s;
        f(j, 0, s-1)
            cout << " " << seq[i][j];
        cout << "\n";
    }
    return 0;
}

