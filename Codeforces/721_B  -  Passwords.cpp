/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |                                   |
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
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
vector<string> s;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, k, cl, l, best, low, wr;
    string x, c;
    while(cin>>n>>k)
    {
        F(i, 1, n)
        {
            cin>>x;
            s.pb(x);
        }
        cin>>c;
        cl = c.length();
        low = 0;
        for(i=0;i<n;i++)
        {
            l = s[i].length();
            if(l<cl)
                low++;
        }
        best = 1;
        best+=low;
        best+=(low/k)*5;
        int high = 0;
        for(i=0;i<n;i++)
        {
            l = s[i].length();
            if(l>cl)
                high++;
        }
        wr = n-high;
        wr +=((n-high-1)/k)*5;
        cout << best << " " << wr << "\n";
        
    }
    return 0;
}


