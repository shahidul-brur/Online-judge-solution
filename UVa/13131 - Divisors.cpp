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
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, k, sum;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        
        if(k==1)
            cout << "0\n";
        else
        {
            sum = 0;
            int r = sqrt(n);
            F(i, 1, r)
            {
                if(n%i==0)
                {
                    if(i%k!=0)
                        sum+=i;
                    j = n/i;
                    if(j!=i && j%k!=0)
                        sum+=j;
                }
            }
            cout << sum << "\n";
        }
    }
    return 0;
}

