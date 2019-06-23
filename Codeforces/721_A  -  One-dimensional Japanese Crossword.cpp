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
    int t, n, i, j, k, siz[500], sz;
    while(cin>>n)
    {
        string s;
        cin>>s;
        k = 0;
        for(i=0;i<n;)
        {
            if(s[i]=='B')
            {
                sz = 1;
                j = i+1;
                for(;j<n;j++)
                {
                    if(s[j]=='B')
                        sz++;
                    else break;
                }
                siz[k++] = sz;
                i=j;
            }
            else i++;

        }
        cout << k << "\n";
        for(i=0;i<k;i++)
            cout << siz[i] << " ";
        cout << "\n";
    }
    return 0;
}

