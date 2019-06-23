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
const int maxn = 10000000;
const int LOGN = 20;
vi primes;
bool comp[maxn+2];
int sp[maxn];
void sieve(){
    primes.pb(2);
    sp[2] = 2;
    for(int i=4;i<=maxn;i+=2) comp[i] = 1, sp[i]=2;
    int r = sqrt(maxn);
    for(int i=3;i<=maxn;i+=2) if(!comp[i]){
        primes.pb(i);
        sp[i]=i;
        if(i>r) continue;
        for(int j=i*i;j<=maxn;j+=(i<<1)){
            comp[j]=1;
            if(!sp[j]) sp[j] = i;
        }
    }
}
int a[100002], n;
bool vis[maxn+2];
vi factors(int num){
    vi facts;
    while(num>1){
        facts.pb(sp[num]);
        int p = sp[num];
        while(num%p==0) num/=p;
    }
    return facts;
}
void fillArray(int idx)
{
    int p=0;
    f2(i,idx,n){
        while(vis[primes[p]]) ++p;
        a[i] = primes[p];
        ++p;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    sieve();
    cin>>n;
    f1(i,n) cin>>a[i];
    f1(i,n){
        int num = a[i];
        for(int j=a[i];;j++){
            vi facts = factors(j);
            bool ok=1;
            for(int pf:facts) if(vis[pf]){
                ok = 0;
                break;
            }
            if(!ok) continue;
            a[i] = j;
            for(int pf:facts) 
                vis[pf] = 1;
            if(j>num){
                fillArray(i+1);
                i = n+1;
            }
            break;
        }
    }
    f1(i,n) cout << a[i] << " ";
    return 0;
}