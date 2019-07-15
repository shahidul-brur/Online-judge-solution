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

bool is_equal(int x1, int y1, int x2, int y2)
{
    return (x1==x2 && y1==y2);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    int x[5], y[5];
    cin>>t;
    while(t--)
    {
        f(i, 1, 4)
        {
            cin>>x[i]>>y[i];
        }
        if(is_equal(x[1], y[1], x[3], y[3]) || is_equal(x[1], y[1], x[4], y[4]) 
           || is_equal(x[2], y[2], x[3], y[3]) || is_equal(x[2], y[2], x[4], y[4]))
        {
            cout << "yes\n";
            continue;
        }
            
        if(y[1]==y[2] && y[2]==y[3] && y[3]==y[4])
        {
            if(min(x[3], x[4])<=max(x[1], x[2]) && min(x[1], x[2])<=max(x[3], x[4]))
            {
                cout << "yes\n";
                continue;
            }
        }
        if(x[1]==x[2] && x[2]==x[3] && x[3]==x[4])
        {
            if(min(y[1], y[2])<=max(y[3], y[4]) && min(y[3], y[4])<=max(y[1], y[2]))
            {
                cout << "yes\n";
                continue;
            }
        }
        cout << "no\n";
    }
    return 0;
}

