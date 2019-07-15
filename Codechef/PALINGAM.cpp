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
int n;
int fa[30], fb[30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string a, b;
    cin>>t;
    while(t--)
    {
        mem(fa, 0);
        mem(fb, 0);
        cin>>a>>b;
        n = a.length();
        
        f(i, 0, n-1)
        {
            fa[a[i]- 'a']++; 
            fb[b[i]- 'a']++; 
        }
        
        bool all_of_A_in_B = 1;
        bool all_of_B_in_A = 1;
        bool two_in_A_not_in_B = 0;
        f(i, 0, 25) 
        {
            if(fa[i]>0 && fb[i]==0)
                all_of_A_in_B = 0;
            if(fa[i]==0 && fb[i]>0)
                all_of_B_in_A = 0;
            if(fa[i]>1 && fb[i]==0)
                two_in_A_not_in_B = 1;
        }
        if(all_of_A_in_B)
        {
            cout << "B\n";
            continue;
        }
        if(all_of_B_in_A)
        {
            cout << "A\n";
            continue;
        }
        if(two_in_A_not_in_B)
        {
            cout << "A\n";
            continue;
        }
        cout << "B\n";
    }
    return 0;
}


