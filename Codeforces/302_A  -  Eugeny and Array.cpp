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
#define rep(i, k) for(int i=0;i<k;i++)
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define sq(a) (a)*(a)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
int cnt[5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n, l, r, q;
    cin>>n>>q;
    rep(i, n)
    {
        cin>>x;
        cnt[x+1]++;
    }
    rep(i, q)
    {
        cin>>l>>r;
        int d = r-l+1;
        if(d & 1)
            cout << "0\n";
        else
        {
            if(cnt[0]>=d/2 && cnt[2]>=d/2)
                cout << "1\n";
            else cout << "0\n";
        }
    }
    return 0;
}

