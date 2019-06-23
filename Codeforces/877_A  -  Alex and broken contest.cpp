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
vector<string> frnd;
int cnt;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    frnd.pb("Danil");
    frnd.pb("Olya");
    frnd.pb("Slava");
    frnd.pb("Ann");
    frnd.pb("Nikita");
    string s;
    while(cin>>s)
    {
        cnt = 0;
        int n = s.length();
        f(i, 0, n-1)
        {
            string name;
            f(j, i, n-1)
            {
                name+=s[j];
                f(k, 0, 4)
                {
                    if(frnd[k]==name)
                    {
                        cnt++;
                        break;
                    }
                }
                if(name.length()==6)
                    break;
            }
        }
        if(cnt==1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}