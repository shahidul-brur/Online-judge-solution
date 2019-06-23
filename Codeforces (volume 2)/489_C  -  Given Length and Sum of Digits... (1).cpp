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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, s;
    while(cin>>m>>s)
    {
        if(m==1 && s==0)
            cout << "0 0\n";
        else if(s>9*m || (m!=1 && s==0))
        {
            cout << "-1 -1\n";
        }
        else
        {
            int rema, onea=0, ninea;
            int remb, nineb;
            
            ninea = nineb = s/9;
            
            rema = remb = s%9;
            
            if(ninea+(rema!=0)<m)
            {
                onea = 1;
                if(rema>0)
                    rema--;
                else 
                {
                    rema = 8;
                    ninea--;
                }
            }
            
            if(onea)
                cout << "1";
            int zero = m-onea-ninea;
            if(rema)
                zero--;
            rep(i, zero)
                cout << "0";
            if(rema)
                cout << rema;
            rep(i, ninea)
                cout << "9";
                
            cout << " ";
            
            rep(i, nineb)
                cout << "9";
            if(remb)
                cout << remb;
            rep(i, (m-nineb-(remb!=0)))
                cout << "0";
            cout << "\n";
        }
    }
    return 0;
}

