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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 200000, N = 1000000, MOD = 1000000007;
const int INF = (int)1e9;
int cnt[MX+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int n, m;
    cin>>s;
    n = s.length();
    cin>>m;
    f(i, 1, m)
    {
        int pos;
        
        cin>>pos;
        --pos;
        if(pos>=n/2)
            pos = n-pos-1;
        cnt[pos]++;
        cnt[n-pos-1]--;
    }
    f(i, 1, n-1)
    {
        cnt[i]+=cnt[i-1];
    }
    f(i, 0, n/2-1)
    {
        //cout << cnt[i] << " ";
        if(cnt[i]%2==1)
            swap(s[i], s[n-i-1]);
    }
    //cout << "\n";
    cout << s << "\n";
    return 0;
}

