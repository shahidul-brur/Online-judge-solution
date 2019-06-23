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
const int maxn = (int)5e6;
const int LOGN = 20;
ll pf[maxn+2];
bool is_composite[maxn+5];
int sp[maxn+5];
void Sieve(){
    for (int i = 2; i <= maxn; i += 2)
        sp[i] = 2; // even numbers have smallest prime factor 2
    for (ll i = 3; i <= maxn; i += 2){
        if (is_composite[i]) continue;
        sp[i] = i; // prime number itself its smallest prime factor
        for (ll j = i; (j*i) <= maxn; j += 2){
            if (!is_composite[j*i]){
                is_composite[j*i] = true;
                sp[j*i] = i;
            }
        }
    }
}

void factorize(int n) // log n
{
    int num = n;
    while(n>1){
        int cnt = 0;
        int tem = n;
        while(tem%sp[n]==0)
            tem/=sp[n], cnt++;
        n = tem;
        pf[num]+=cnt;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    Sieve();
    f1(i,maxn) factorize(i);
    f1(i,maxn)
        pf[i]+=pf[i-1];
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;
        cout << pf[a] - pf[b] << "\n";
    }
    return 0;
}
