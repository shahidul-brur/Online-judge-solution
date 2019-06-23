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
//             0123456789
const int MX = 200000;
int ara[MX+5];
int cnt[MX+5];
bool used[MX+5];
vi missing;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    f(i, 1, n)
    {
        cin>>ara[i];
        cnt[ara[i]]++;
    }
    f(i, 1, n)
    {
        if(cnt[i]==0)
            missing.pb(i);
    }
    int pos = 0;
    f(i, 1, n)
    {
        if(cnt[ara[i]]==1 || (!used[ara[i]] && ara[i]<missing[pos]))
            used[ara[i]] = 1;
        else 
        {
            cnt[ara[i]]--;
            ara[i] = missing[pos++];
        }
    }
    cout << (int)missing.sz << "\n";
    f(i, 1, n)
    {
        if(i>1)
            cout << " ";
        cout << ara[i];
    }
    cout << "\n";
    return 0;
}

