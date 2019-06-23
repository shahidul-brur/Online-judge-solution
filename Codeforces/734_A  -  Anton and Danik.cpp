/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
|                                   |
\*=================================*/

#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i, b, a) for(int i=b;i>=a;i--)
#define sq(a) (a)*(a)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int n, a=0, d=0;
    string s;
    cin>>n;
    cin>>s;
    F(i, 0, n-1)
    {
        if(s[i]=='A')
            a++;
        else d++;
    }
    if(a>d)
        cout << "Anton\n";
    else if(d>a)
        cout << "Danik\n";
    else cout << "Friendship\n";
    return 0;
}

