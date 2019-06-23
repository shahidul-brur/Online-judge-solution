/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
ll v(char c)
{
    ll val;
    if(c=='f')
        val = 1;
    else if(c=='e')
        val = 2;
    else if(c=='d')
        val = 3;
    else if(c=='a')
        val = 4;
    else if(c=='b')
        val = 5;
    else if(c=='c')
        val = 6;
    
    return val;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    string s;
    ll n;
    while(cin>>s)
    {
        int len = s.length();
        n = 0LL;
        F(i, 0, len-2)
        {
            n = n*10 + (s[i] - '0');
        }
        ll d = (n+3)/4 - 1;
        ll pre = d*16;
        ll tim;
        if(n%2==1)
        {
            tim = pre+v(s[len-1]);
        }
        else
        {
            tim = pre + 7 + v(s[len-1]);
        }
        cout << tim << "\n";
    }
    return 0;
}
