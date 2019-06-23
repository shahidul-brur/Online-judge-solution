/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define PI              acos(-1.0)
#define eps             1e-6
#define mem(ara, val)   memset(ara, val, sizeof(ara))
const int MX = 100000;
const int MOD = 1000000007;
const int INF = (int)1e9;
pair<pair<int, int>, char> logo[8];
int side;
char board[305][305];
bool cmp(pair<pair<int, int>, char> a, pair<pair<int, int>, char> b)
{
    if(a.ff==b.ff)
        return a.ss>b.ss;
    return a.ff>b.ff;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    char c = 'A';
    f(i, 1, 3)
    {
        cin>>logo[i].ff.ff >> logo[i].ff.ss;
        logo[i].ss = c;
        c++;
        if(logo[i].ff.ff<logo[i].ff.ss)
            swap(logo[i].ff.ff, logo[i].ff.ss); // x= L(l to r) > y = W ( u to d)
    }
    
    sort(logo+1, logo+4, cmp);
    int area = 0;
    for(int i =1;i<=3;i++)
        area+=logo[i].ff.ff * logo[i].ff.ss;
    side = sqrt(area);
    
    if(side*side!=area)
    {
        cout << "-1\n";
        return 0;
    }
    int equ=0;
    for(int i = 1;i<=3;i++)
    {
        
        if(logo[i].ff.ff==side)
            equ++;
        if(logo[i].ff.ff>side)
        {
            cout << "-1\n";
             return 0;
        }
    }
    if(equ==2 || equ==0)
    {
        cout << "-1\n";
        return 0;
    }
    
    if(equ==3 && (logo[1].ff.ss+logo[2].ff.ss+logo[3].ff.ss==side))
    {
        cout << side << "\n";
        for(int  i = 1;i<=logo[1].ff.ss;i++)
        {
            for(int j = 1;j<=side;j++)
                cout << logo[1].ss;
            cout << "\n";
        }
        for(int  i = logo[1].ff.ss+1;i<=logo[1].ff.ss+logo[2].ff.ss;i++)
        {
            for(int j = 1;j<=side;j++)
                cout << logo[2].ss;
            cout << "\n";
        }
        for(int  i = logo[1].ff.ss+ logo[2].ff.ss+1;i<=logo[1].ff.ss+logo[2].ff.ss+logo[3].ff.ss;i++)
        {
            for(int j = 1;j<=side;j++)
                cout << logo[3].ss;
            cout << "\n";
        }
        return 0;
    }
    
    if(logo[2].ff.ss!=side-logo[1].ff.ss)
        swap(logo[2].ff.first, logo[2].ff.second);
    if(logo[3].ff.ss!=side-logo[1].ff.ss)
        swap(logo[3].ff.first, logo[3].ff.second);
        
    if(logo[2].ff.ss!=side-logo[1].ff.ss || logo[3].ff.ss!=side-logo[1].ff.ss || logo[2].ff.first+logo[3].ff.first!=side)
    {
        cout << "-1\n";
        return 0;
    }
    
    cout << side << "\n";
    for(int i = 1;i<=logo[1].ff.ss;i++)
    {
        for(int j = 1;j<=side;j++)
            cout << logo[1].ss;
        cout << "\n";
    }
    for(int i = logo[1].ff.ss+1;i<=side;i++)
    {
        for(int j = 1;j<=logo[2].ff.first;j++)
            cout << logo[2].ss;
        for(int j = logo[2].ff.first+1;j<=side;j++)
            cout << logo[3].ss;
        cout << "\n";
    }
    return 0;
}


