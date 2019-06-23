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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int p[3][2],d;
    std::vector<ii> ans;
    f0(i,3) cin>>p[i][0]>>p[i][1];
    if(p[0][0]==p[1][0] && p[1][0]==p[2][0]){
        int loy = min(p[0][1], min(p[1][1], p[2][1]));
        int hiy = max(p[0][1], max(p[1][1], p[2][1]));
        d = hiy-loy+1;
        f2(i,loy,hiy) ans.pb(mp(p[0][0], i));
    }
    else if(p[0][1]==p[1][1] && p[1][1]==p[2][1])
    {
        int lox = min(p[0][0], min(p[1][0], p[2][0]));
        int hix = max(p[0][0], max(p[1][0], p[2][0]));
        d = hix-lox+1;
        f2(i,lox,hix) ans.pb(mp(i, p[0][1]));
    }
    else
    {
        vii pt;
        f0(i,3) pt.pb(mp(p[i][0], p[i][1]));
        sort(all(pt));
        int lox = pt[0].ff;
        int hix = pt[2].ff;
        int loy = min(pt[0].ss, pt[2].ss);
        int hiy = max(pt[0].ss, pt[2].ss);
        if(pt[1].ss>hiy){
            for(int x=lox;x<=hix;x++){
                ans.pb(mp(x,hiy));
            }
            int x;
            if(pt[0].ss==loy) x = pt[0].ff;
            else x = pt[2].ff;
            for(int y=loy;y<hiy;y++){
                ans.pb(mp(x,y));
            }
            x = pt[1].ff;
            for(int y=hiy+1;y<=pt[1].ss;y++){
                ans.pb(mp(x,y));
            }
        }
        else if(pt[1].ss<loy)
        {
            for(int x=lox;x<=hix;x++){
                ans.pb(mp(x,loy));
            }
            int x;
            if(pt[0].ss==hiy) x = pt[0].ff;
            else x = pt[2].ff;
            for(int y=loy+1;y<=hiy;y++){
                ans.pb(mp(x,y));
            }
            x = pt[1].ff;
            for(int y=loy-1;y>=pt[1].ss;y--){
                ans.pb(mp(x,y));
            }
        }
        else
        {
            for(int x=lox;x<=hix;x++){
                ans.pb(mp(x,pt[1].ss));
            }
            if(pt[0].ss>pt[1].ss){
                for(int y=pt[1].ss+1;y<=pt[0].ss;y++){
                    ans.pb(mp(pt[0].ff,y));
                }
            }
            else if(pt[2].ss>pt[1].ss){
                for(int y=pt[1].ss+1;y<=pt[2].ss;y++){
                    ans.pb(mp(pt[2].ff,y));
                }

            }

            if(pt[0].ss<pt[1].ss){
                for(int y=pt[1].ss-1;y>=pt[0].ss;y--){
                    ans.pb(mp(pt[0].ff,y));
                }
            }
            else if(pt[2].ss<pt[1].ss){
                for(int y=pt[1].ss-1;y>=pt[2].ss;y--){
                    ans.pb(mp(pt[2].ff,y));
                }
            }
        }
        
    }
    d = ans.size();
    cout << d << "\n";
    for(ii p:ans){
        cout << p.ff << " " << p.ss << "\n";
    }
    return 0;
}
