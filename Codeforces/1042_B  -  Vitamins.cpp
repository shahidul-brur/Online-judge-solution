/*==============================================*\ 
ID:          shahidul_brur

Name:     Md. Shahidul Islam           
Study:      CSE, BRUR                 
Address:  Rangpur, Bangladesh
                
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com(in Bengali),
       shahidul-brur-en.blogspot.com(in English) 
\*===============================================*/
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<int, ll> il;
typedef vector<ii> vii;
typedef vector<il> vil;
typedef vector<li> vli;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz size()
#define all(a)  a.begin(), a.end()
#define mem(a, b)     memset(a, b, sizeof(a))
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
#define rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
int c[1004];
string v[1005];
set<ii > s[5];
bool vit[1005][5];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin>>n;
    int ans = INT_MAX;
    f1(i,n)
    {
        cin>>c[i]>>v[i];
        for(char x:v[i]) 
            s[x- 'A'].insert(mp(c[i], i)), vit[i][x - 'A' ] = 1;
        if(v[i].size()==3) ans = min(ans, c[i]);
    }
    f0(i,3) if(s[i].size()==0)
    {
        cout << "-1\n";
        return 0;
    }
    ii op[3];
    f0(i,3) 
    {
        op[i] = *s[i].begin();
        //cout << op[i].first << " " << v[op[i].second] << "\n";
    }
    f0(i,3)
    {
        bool ok[3];
        f0(t,3) ok[t]=0;
        for(char x:v[op[i].second]) ok[x-'A']=1;
        f0(j,3)
        {
            if(i==j || ok[j]==1) continue;
            for(char x:v[op[j].second]) ok[x-'A']=1;
            int cur = op[i].first;
            cur+=op[j].first;
            f0(k, 3)
            {
                if(k==i || k==j || ok[k]==1) continue;
                cur+=op[k].first;
                break;
            }
            f0(t,3) ok[t]=0;
            for(char x:v[op[i].second]) ok[x-'A']=1;
            ans = min(ans, cur);
        }
    }
    cout << ans;
    return 0;
}


