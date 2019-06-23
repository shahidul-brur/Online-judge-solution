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
int b[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        multiset<int> a;
        bool four = 0;
        int s1,s2;
        f1(i,n)
        {
            int x;
            cin>>x;
            if(a.count(x)==4)
            {
                if(!four)
                {
                    four = 1;
                    s1 = x;
                }
                continue;
            }
            a.insert(x);
        }
        if(four)
        {
            cout << s1 << " " << s1 << " ";
            cout << s1 << " " << s1 << "\n";
            continue;
        }
        int p,q;
        int siz = 0;
        int pr = 0;
        for(auto it = a.begin();it!=a.end();it++)
        {
            int v = *it;
            if(v==pr) continue;
            pr = v;
            int cnt = a.count(v);
            if(cnt==2 || cnt==3) b[++siz] = v;
            else if(cnt>=4)
            {
                b[++siz] = v;
                b[++siz] = v;
            }
        }
        p = b[1];
        q = b[2];
        ll peri = 4*(p+q)*(p+q);
        ll area = p*q;
        s1 = p,s2 = q;
        f1(i,siz-1)
        {
            p = b[i];
            q = b[i+1];
            ll c_peri = 4*(p+q)*(p+q);
            ll c_area = p*q;
            if(c_peri*area<peri*c_area)
            {
                s1 = p;
                s2 = q;
                area = c_area;
                peri = c_peri;
            }
        }
        cout << s1 << " " << s1 << " " << s2 << " " << s2 << "\n";
    }
    return 0;
}