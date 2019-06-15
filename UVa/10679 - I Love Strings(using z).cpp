/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               1000005
#define inf             1e9
bool zfunc(string p, string T)
{
    int m = p.length();
    string s = p + "$" + T;
    int n = p.length()+T.length()+1;
    int z[n+2];
    z[0] = 0;
    int left =0, right = 0;
    for(int i=1;i<n;i++)
    {
        z[i] = 0;
        if(i<=right)
            z[i] = min(z[i-left], right-i+1);
        while(i+z[i]<n && s[i+z[i]]==s[z[i]])
            z[i]++;
        if(i+z[i]-1>right)
            left = i, right = i+z[i]-1;
        if(z[i]==m)
            return 1;
    }
    return 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    //printf("%c", 255);
    int t, q;
    string s, p;
    cin>>t;
    while(t--)
    {
        cin>>s;
        cin>>q;
        while(q--)
        {
            cin>>p;
            if(zfunc(p, s))
                cout << "y\n";
            else cout << "n\n";
        }
    }
    return 0;
}

