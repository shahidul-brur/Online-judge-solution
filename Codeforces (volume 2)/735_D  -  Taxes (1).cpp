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
#define rep(i, k) for(int i=0;i<k;i++)
#define RF(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 1000005
#define inf 1e9
bool isPrime(int n)
{
    if(n==2)
        return 1;
    int r = sqrt(n);
    if(n%2==0)
        return 0;
    for(int i=3;i<=r+1;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        if(n==2)
        cout << "1\n";
        else
        {
            if(n%2==0)
                cout << "2\n";
            else
            {
                if(isPrime(n))
                    cout << "1\n";
                else if(isPrime(n-2))
                    cout << "2\n";
                else cout << "3\n";
            }
        }
    }
    return 0;
}



