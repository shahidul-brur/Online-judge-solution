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
const int N = 300002;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string cmd;
    int n, x;
    while(cin>>n)
    {
        int cur = 1;
        int cnt = 0;
        vi box;
        f(i, 1, 2*n)
        {
            cin>>cmd;
            if(cmd=="add")
            {
                cin>>x;
                box.pb(x);
            }
            else
            {
                if(box.size()>0)
                {
                    int top = box.back();
                    if(top==cur)
                    {
                        box.pop_back();
                    }
                    else
                    {
                        cnt++;
                        box.clear();
                    }
                }
                cur++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

