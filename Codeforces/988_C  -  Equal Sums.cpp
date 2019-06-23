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
/*
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
*/
using namespace std;

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

inline int Int(){int x; scanf("%d", &x);return x;}
inline long Long() {long x;scanf("%ld", &x);return x;}
inline ll LLong() {ll x;scanf("%lld", &x);return x;}
inline float Float() {float x;scanf("%f", &x);return x;}
inline double Double() {double x;scanf("%lf", &x);return x;}
inline ii Pair() {ii p; scanf("d %d", &p.ff, &p.ss);return p;}
void S(char *x) {scanf("%s", x);}

void pI(int x) {printf("%d", x);}
void pL(long x) {printf("%ld", x);}
void pLL(ll x) {printf("%lld", x);}
void pUL(ull x) {printf("%llu", x);}
void pF(float x) {printf("%f", x);}
void pD(double x) {printf("%f", x);}
void pS(char x[]) {printf("%s", x);}
#define pCas printf("Case %d:",cas)
#define NL printf("\n")
#define SP printf(" ")

#define I Int()
#define L Long()
#define LL LLong()
#define F Float()
#define D Double()
#define P Pair()

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
int len[maxn], s[maxn];
map<int, ii> idx;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int k;
    cin>>k;
    f1(i, k)
    {
        cin>>len[i];
        map<int,int> items;
        f1(j, len[i])
        {
            int x;
            cin>>x;
            s[i]+=x;
            if(!items.count(x))
                items[x] = j;
        }
        for(auto it:items)
        {
            int cur = s[i]-it.ff;
            if(idx.count(cur))
            {
                cout << "YES\n";
                cout << i << " " << it.ss << "\n";
                cout << idx[cur].first << " " << idx[cur].ss << "\n";
                return 0;
            }
        }
        for(auto it:items)
        {
            int cur = s[i]-it.ff;
            if(!idx.count(cur))
            {
                idx[cur] = mp(i, it.ss);
            }
        }
    }
    cout << "NO\n";
    /*
    bool found = 0;
    int a, b, id_a, id_b;
    f1(i, k)
    {
        //cout << i << ":\n======\n";
        for(auto it:idx[i])
        {
            int cur = it.first;
            int id_a =  it.second;
           // cout << "\n" << cur << " " << id_a << " -> ";
            f2(l, i+1, k)
            {
                if(idx[l].find(cur)==idx[l].end()) continue;
                //cout << idx[l][cur] << " !\n";
                a = i;
                b = l;
                id_a = it.second;;
                id_b = idx[l][cur];
                cout << "YES\n";
                cout << a << " " << id_a << "\n";
                cout << b << " " << id_b << "\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    */
    return 0;
}
