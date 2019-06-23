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
vi pos[27];
int cnt[27][1505];
bool ocr[27][1505];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int n, q, m;
    char c;
    cin>>n;
    cin>>s;
    //cout << s << "\n";
    f(i, 0, n-1)
    {
        pos[s[i] - 'a'].pb(i);
        ocr[s[i] - 'a'][i] = 1;
    }
    f(i, 0, 25)
    {
        f(j, 0, n-1)
        {
            int tot = 0;
            int need = 0;
            f(k, j, n-1)
            {
                tot++;
                if(ocr[i][k]==0)
                    need++;
                cnt[i][need] = max(cnt[i][need], tot);
            }
        }
        f(j, 1, n)
            cnt[i][j] = max(cnt[i][j], cnt[i][j-1]);
    }
    
    cin>>q;
    while(q--)
    {
        cin>>m>>c;
        cout << cnt[c-'a'][m] << "\n";
    }
    return 0;
}

