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
const int MX = 100000, N = 1000000, MOD = 1000000007;
const int INF = (int)1e9;
int pos[1005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, t;
    string A, T;
    while(cin>>a>>t)
    {
        cin>>A>>T;
        int mini = 100005;
        f(i, 0, t-a)
        {
            int cnt= 0;
            f(j, 0, a-1)
            {
                //cout << T[i+j] << " " << A[j] << "\n";
                if(T[i+j]!=A[j])
                    cnt++;
            }
            //cout << i << " : " << cnt << "\n";
            if(cnt<mini)
            {
                mini = cnt;
                int k = 0;
                f(j, 0, a-1)
                {
                    if(T[i+j]!=A[j])
                    {
                        pos[k++] = j+1;
                    }
                }
            }
        }
        cout << mini << "\n";
        f(i, 0, mini-1)
        {
            if(i>0) cout << " ";
            cout << pos[i];
        }
        cout << "\n";
    }
    return 0;
}

