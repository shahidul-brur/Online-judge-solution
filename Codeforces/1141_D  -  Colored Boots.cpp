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
vi pl[28], pr[28];
vii ans;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    string l, r;
    cin>>l>>r;
    f0(i,n)
    {
        if(l[i]=='?') pl[26].pb(i+1);
        else pl[l[i]-'a'].pb(i+1);
        
        if(r[i]=='?') pr[26].pb(i+1);
        else pr[r[i]-'a'].pb(i+1);
    }
    f0(i,26)
    {
        while(pl[i].size()>0 && pr[i].size()>0){
            ans.pb(mp(pl[i].back(), pr[i].back()));
            pl[i].pop_back();
            pr[i].pop_back();
        }
    }
    while(pl[26].size()){
        bool ok = 0;
        f0(i,26)
        {
            if(pr[i].size()>0)
            {
                ans.pb(mp(pl[26].back(), pr[i].back()));
                pr[i].pop_back(); 
                ok=1;      
                break;
            }
        }
        if(!ok)
        {
            if(pr[26].size()>0)
            {
                ans.pb(mp(pl[26].back(), pr[26].back()));
                pr[26].pop_back();
            }
            else break;
        }
        pl[26].pop_back();
    }
    while(pr[26].size()){
        bool ok = 0;
        f0(i,26)
        {
            if(pl[i].size()>0)
            {
                ans.pb(mp(pl[i].back(), pr[26].back()));
                pl[i].pop_back(); 
                ok=1;      
                break;
            }
        }
        if(!ok)
        {   
            if(pl[26].size()>0)
            {
                ans.pb(mp(pl[26].back(), pr[26].back()));
                pl[26].pop_back();
            }
            else break;
        }
        pr[26].pop_back();
    }
    int mx = ans.size();
    cout << mx << "\n";
    f0(i,mx)
    {
        //cout << l[ans[i].ff-1] << " " << r[ans[i].ss-1] << " = ";
        cout << ans[i].ff << " " << ans[i].ss << "\n";
    }
    return 0;
    
}
