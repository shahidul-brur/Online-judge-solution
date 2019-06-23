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
#define N               200005
#define inf             1e9
int px[N], py[N];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int x, y, k;
    string s;
    int n;
    while(cin>>n)
    {
        cin>>s;
        //if(n<=)
        x = y = 0;
        //x0 = y0 = 0;
        int i = 0;
        if(s[i]=='U')
            y++;
        else if(s[i]=='D')
            y--;
        else if(s[i]=='R')
            x++;
         else if(s[i]=='L')
            x--;
        k = 1;
        //px[0] = x;
       // py[0] = y;
        rep1(i, n)
        {
            if(s[i]=='U')
            {
                if(y==-1)
                {
                    k++;
                    x=0;
                }
                y = 1;
                //y0++;
            }
            else if(s[i]=='D')
            {
                if(y==1)
                {
                    k++;
                    x = 0;
                }
                y = -1;
                //y0--;
            }
            else if(s[i]=='R')
            {
                if(x==-1)
                {
                    k++;
                    y=0;
                }
                x = 1;
                //x0++;
            }
             else if(s[i]=='L')
            {
                if(x==1)
                {
                    k++;
                   y=0;
                }
                 x = -1;
                 //x0--;
            }
            //px[i] = x0;
            //py[i] = y0;
        }
        cout << k << "\n";
    }
    return 0;
}
