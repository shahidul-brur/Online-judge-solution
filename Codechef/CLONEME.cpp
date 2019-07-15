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
int a[MX], t1[MX], t2[MX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, b1, e1, b2, e2, t, p, q;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        f(i, 1, n)
        {
            cin>>a[i];
        }
        while(m--)
        {
            cin>>b1>>e1;
            cin>>b2>>e2;
            p = q = 0;
            f(i, b1, e1)
                t1[p++] = a[i];
            f(i, b2, e2)
                t2[q++] = a[i];
            sort(t1, t1+p);
            sort(t2, t2+q);
            int dis = 0;
            f(i, 0, p-1)
            {
                if(t1[i]!=t2[i])
                {
                    dis++;
                    if(dis>1)
                        break;
                }
            }
            if(dis>1)
                cout << "NO\n";
            else cout << "YES\n";
        }
    }
    return 0;
}

