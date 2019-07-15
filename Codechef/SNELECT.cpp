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
bool vis[105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    int m, s, e;
    string ss;
    cin>>t;
    while(t--)
    {
        mem(vis, 0);
        cin>>ss;
        int n = ss.length();
        m = s = e = 0;
        f(i, 0, n-1)
        {
            if(ss[i]=='m')
                m++;
            else 
            {
                s++;
                if(i>0 && ss[i-1]=='m' && vis[i-1]==0)
                {
                    vis[i-1] = 1;
                    e++;
                }
                else if(i<n-1 && ss[i+1]=='m' && vis[i+1]==0)
                {
                    vis[i+1] = 1;
                    e++;
                }
            }
        }
        s-=e;
        if(s==m)
            cout << "tie\n";
        else if(s>m)
            cout << "snakes\n";
        else cout << "mongooses\n";
    }
    return 0;
}

