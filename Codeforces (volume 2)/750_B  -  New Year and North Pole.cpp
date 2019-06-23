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
#define N               1000005
#define inf             1e9
int pos;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, x;
    char s[20];
    while(cin>>n)
    {
        pos = 0;
        bool y = 1;
        rep(i, n)
        {
            cin>>x;
            cin>>s;
            if((pos==0  && strcmp(s, "South")!=0)  || (pos==20000) && strcmp(s, "North")!=0)
            {
                y = 0;
            }
            
            if(y==1)
            {
                if(strcmp(s, "South")==0)
                    pos+=x;
                if(strcmp(s, "North")==0)
                    pos-=x;
                
                if(pos>20000 || pos<0)
                    y = 0;
            }
        }
        
        if(pos!=0)
            y = 0;
        if(y)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

