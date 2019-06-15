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
const int MX = (1<<20)+5;
bool is_composite[MX];
int sp[MX];
vector<ii> fac[MX];
int cnt[30];
void Sieve(){
	for (int i = 2; i < MX; i += 2)
        sp[i] = 2; // even numbers have smallest prime factor 2
	for (ll i = 3; i < MX; i += 2){
		if (is_composite[i]) continue;
        sp[i] = i; // prime number itself its smallest prime factor
        for (ll j = i; (j*i) < MX; j += 2){
            if (!is_composite[j*i]){
                is_composite[j*i] = true;
                sp[j*i] = i;
            }
        }
	}
}

void factorize() // log n
{
    for(int num=2;num<MX;num++){
        int n = num;
        while(n>1){
            int pw=0,prime = sp[n];
            int tem = n;
            while(tem%sp[n]==0)
                tem/=sp[n], ++pw;
            fac[num].push_back(mp(prime,pw));
            n = tem;
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    Sieve();
    factorize();
    int n, base;
    while(cin>>n>>base)
    {
        if(n==0){
            cout << "0 1\n";
            continue;
        }
        
        double log_base = 0;
        int fct = fac[base].size();
        mem(cnt, 0);
        for(int i=1;i<=n;i++){
            log_base+=log(i*1.0)/log(base*1.0);
            for(int j=0;j<fct;j++){
                int div = fac[base][j].first;
                int num = i, pw=0;
                while(num%div==0){
                    pw++, num/=div;
                }
                cnt[j]+=pw;
            }
        }
        int digit = floor(log_base) + 1;
        int zero = INT_MAX;
        for(int j=0;j<fct;j++){
            int lagbe = fac[base][j].second;
            int ase = cnt[j];
            //cout << lagbe << " " << ase << "\n";
            if(ase==0) {
                zero = 0;
                break;
            }
            zero = min(zero, ase/lagbe);
        }
        cout << zero << " " << digit << "\n";
    }
    return 0;
}

