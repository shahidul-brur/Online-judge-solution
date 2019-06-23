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
int f[30];
int bs(int cost)
{
    int b = 1, e = 10000;
    int ret = 1;
    while(b<=e)
    {
       int m = (b+e)/2;
       if(m*(m+1)/2==cost)
         return m;
       if(m*(m+1)/2<cost)
       {
           b = m+1;
           ret = max(ret, m);
       }
       else 
       {
           e = m-1;
       }
    }
    return ret;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int cost;
    while(cin>>cost)
    {
        if(cost==0)
        {
            cout << "a\n";
            return 0;
        }
        mem(f, 0);
        int cur = 0;
        while(cost>0)
        {
            int x  = bs(cost);
            f[cur] = x+1;
            cost -= x*(x+1)/2;
            cur++;
        }
        f(i, 0, 25)
        {
            f(j, 1, f[i])
                cout << (char)(i + 'a');
        }
        cout << "\n";
    }
    return 0;
}

