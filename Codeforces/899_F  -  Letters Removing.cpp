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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

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
inline ii Pair() {ii p; scanf("%d %d", &p.ff, &p.ss);return p;}
void Char(char *x) {scanf("%s", x);}

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

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
set<int> pos[64];
int id(char c)
{
    if(isdigit(c))
            return c-'0';
        else if(islower(c))
            return c-'a'+10;
        return c - 'A'+36;
}
char ch(int p)
{
    if(p<10)
        return (char)(p+'0');
    if(p<36)
        return (char)(p-10+'a');
    return (char)(p-36+'A');
}
char s[maxn];
ordered_set S;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n = Int(), m=Int();
    Char(s);
    f0(i,n){
        S.insert(i+1);
        if(isdigit(s[i]))
            pos[id(s[i])].insert(i+1);
        else if(islower(s[i]))
            pos[id(s[i])].insert(i+1);
        else pos[id(s[i])].insert(i+1);
    }
    while(m--){
        int l = Int(), r = Int();
        int c = getchar();
        c = getchar();
        l=*S.find_by_order(l-1);
        r=*S.find_by_order(r-1);
        //cout << c  << " : " << l << " , " << r << " = > ";
        int p = id(c);
        auto lo = pos[p].lower_bound(l);
        auto hi = pos[p].upper_bound(r);
        for(auto it = lo;it!=hi;it++){
            //cout << *it << ", ";
            s[*it-1] = '#';
            S.erase(*it);
        }
        //cout << endl;
        pos[p].erase(pos[p].lower_bound(l), pos[p].upper_bound(r));
    }
//    f1(i,n) ans[i] = '#';
//    ans[n+1] = 0;
//    f0(i,62)
//    {
//        for(int p:pos[i])
//        {
//            cout << ch(i) << ": " << p << "\n";
//            ans[p]=ch(i);
//        }
//    }
    f0(i,n) if(s[i]!='#')
        cout << s[i];
    return 0;
}


