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
int a[200005];
int main()
{
   // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        F(i, 0, n-1)
        {
            cin>>a[i];
        }
        int cp = 0;
        int d=0;
        int y=1;
        F(i, 0, n-1)
        {
            if(cp==1 && a[i]==0)
            {
                y=0;
                break;
            }
            if(cp==1)
            {
                if(a[i]%2==1)
                {
                    cp=0;
                }
            }
            else
            {
                if(a[i]%2==1)
                {
                    cp=1;
                }
            }
            
        }
        if(cp!=0)
            y=0;
        if(y==1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


