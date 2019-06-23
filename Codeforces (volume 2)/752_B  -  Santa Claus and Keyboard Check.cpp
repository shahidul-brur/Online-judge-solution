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
bool used[30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int pos;
    string s, t;
    map<char, char> m;
    while(cin>>s>>t)
    {
        m.clear();
        mem(used, 0);
        pos =1;
        int l = s.length();
        rep(i, l)
        {
            if(s[i]==t[i])
            {
                
                int a = s[i] - 'a';
                if(used[a]==1 && m[s[i]] != s[i])
                {
                    pos = 0;
                    break;
                }
                 m[s[i]] = s[i];
                used[a] = 1;
                continue;
            }
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            
            if(used[a]!=used[b])
            {
                pos = 0;
                break;
            }
            
            if(used[a]==1 && used[b]==1 && (m[s[i]]!=t[i] || m[t[i]]!=s[i]))
            {
                pos = 0;
                break;
            }
            if(used[a]==0 && used[b]==0)
            {
                m[s[i]] = t[i];
                m[t[i]] = s[i];
                used[a] = used[b] = 1;
            }
        }
        int k = 0;
        rep(i, 26)
        {
            if(used[i]==1)
            {
                char c1 = 'a' + i;
                char c2 = m[c1];
                if(c1!=c2)
                    k++;
                int b = c2 - 'a';
                //cout << c1 << " " << c2 << "\n";
                //cout << " # " << b << "\n";
                used[b] = 0;
            }
        }
        if(pos==0)
            cout << "-1\n";
        else
        {
            cout << k << "\n";
            rep(i, 26)
            {
                if(used[i]==1)
                {
                    k++;
                    char c1 = 'a' + i;
                    char c2 = m[c1];
                    cout << c1 << " " << c2 << "\n";
                }
            }
        }
    }
    return 0;
}

