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
const int MX = 1000005;
const int MOD = 1000000007;
const int INF = (int)1e9;
//int p[MX];
int used[30], last[30], fast[30];
int grd[30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k;
    string s;
    while(cin>>n>>k)
    {
        cin>>s;
        f(i, 0, 27) used[i] = grd[i] = 0;
        f(i, 0, n-1)
        {
           // p[i] = 0;
            int l = s[i] - 'A';
            if(used[l]==-1)
            {
                last[l] = fast[l] = i;
                used[i] = 1;
            }
            else 
            {
                last[l] = i;
            }
        }
        //p[n] = 0;
//        f(i, 0, 25)
//        {
//            if(used[i]==1)
//            {
//                p[fast[i]]--;
//                p[last[i]+1]++;
//            }
//        }
        int rem = k;
        bool yes = 0;
        f(i, 0, n-1)
        {
            int l = s[i] - 'A';
            if(grd[l]==0 && rem<=0)
            {
                yes = 1;
                break;
            }
            
            if(grd[l]==1 && last[l]==i)
            {
                rem++;
            }
            else if(grd[l]==0)
            {
                grd[l] = 1;
                if(last[l]!=i)
                    rem--;
            }
        }
        if(yes==1)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}


