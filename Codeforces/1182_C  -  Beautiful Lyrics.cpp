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
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
const int maxn = (int)1e5+5;
const int LOGN = 20;
string vow = "aeiou";
string w[maxn];
int vwl[maxn];
//int cnt[5][maxn];
vi str[5][maxn];
vi ext[maxn];
set<int> ase;
vi fin;
vii ans[2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, mx = 0;
    cin>>n;
    f0(i,n)
    {
        cin>>w[i];
        int last, siz = w[i].size();
        f0(j,siz)
        {
            f0(k,5) if(w[i][j]==vow[k]){
                vwl[i]++;
                last = k;
            }
        }
        mx = max(mx, vwl[i]);
        //cnt[last][v]++;
        str[last][vwl[i]].pb(i);
    }
    f0(k,5)
    {
        f1(i,mx)
        {
            if(str[k][i].size()%2==1){
                ext[i].pb(str[k][i].back());
                str[k][i].pop_back();
                if(ext[i].size()==2)
                    ase.insert(i);
            }
            for(int id:str[k][i]){
                fin.pb(id);
//                cout << k << ", " << i << ": " << id << "\n";
            }
        }
    }
//    cout << "\n!!  here\n";
    int tot = 0;
//    cout << fin.size() << "\n";
//    for(int i:fin) cout << i << ", ";
//    cout << "\n";
//    for(int i:ase) cout << i << ", ";
//    cout << "\n";
    if(fin.size()==0){
        cout << "0";
        return 0;
    }
    
    for(int i=0;i<(int)fin.size()-1;i+=2){
        //cout << i << " !!\n";
        if(ase.size()>0){
            int k = *ase.begin();
            int last1=ext[k].back(); ext[k].pop_back();
            int last2=ext[k].back(); ext[k].pop_back();
            ans[0].pb(mp(fin[i],fin[i+1]));
            ans[1].pb(mp(last1,last2));
            tot++;
            if(ext[k].size()<2) ase.erase(k);
        }
        else
        {
            if(i+3<fin.size()){
                int last1=fin.back(); fin.pop_back();
                int last2=fin.back(); fin.pop_back();
                ans[0].pb(mp(fin[i],fin[i+1]));
                ans[1].pb(mp(last1,last2));
                tot++;
            }
        }
    }
    
    cout << tot << "\n";
    
    f0(i,tot)
    {
        cout << w[ans[1][i].ff] << " ";
        cout << w[ans[0][i].ff] << "\n";
        
        cout << w[ans[1][i].ss] << " ";
        cout << w[ans[0][i].ss] << "\n";
    }
    
    return 0;
}
