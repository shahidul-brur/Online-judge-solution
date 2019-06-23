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
int a[105], b[105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    while(cin>>n>>k)
    {
        f(i, 1, n)
        {
            cin>>a[i];
        }
        f(i, 1, k)
        {
            cin>>b[i];
        }
        if(k>1)
            cout << "Yes\n";
        else
        {
            bool yes = 0;
            f(i, 1, n)
            {
                if(a[i]==0)
                {
                    a[i] = b[1];
                    break;
                }
            }
            f(i, 2, n)
            {
                if(a[i]<a[i-1])
                {
                    yes = 1;
                    break;
                }
            }
            if(yes==1)
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}

