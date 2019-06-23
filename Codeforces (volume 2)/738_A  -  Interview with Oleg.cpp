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
#define N 210
#define inf 1e9
int n;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, j;
    string s;
    while(cin>>n)
    {
        cin>>s;
        for(int i=0;i<n;)
        {
            bool y=0;
            if(s[i]=='o')
            {
                j = i+1;
                bool y=0;
                while(j<n-1 && s[j]=='g' && s[j+1]=='o')
                {
                    y=1;
                    j+=2;
                }
                if(y)
                {
                    cout << "***";
                    i = j;
                }
                else 
                {
                    cout << s[i++];
                }
            }
            else cout << s[i++];
        }
        cout << "\n";
    }
    return 0;
}



