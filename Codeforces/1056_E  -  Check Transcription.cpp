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
const int maxn = (int)1e6+5;
const int LOGN = 20;
ll h[maxn], inv[maxn], pwr[maxn];

ll mod_pow(ll b, int e)
{
    if (e == -1) e = MOD - 2;
    ll ret = 1;
    while (e) {
        if (e & 1) 
            ret = (ret * b) % MOD;
        b = (b * b) % MOD, e >>= 1;
    }
    return ret;
}
ll Hash(int l, int r)
{
    ll ret = (h[r]+MOD-h[l-1])%MOD;
    ret = (ret*inv[l-1])%MOD;
    return ret;
}
char t[maxn], s[maxn];
int cnt[2];

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll P = 31;
    ll I = mod_pow(P, -1);
    pwr[0]=inv[0]=1;
    for(int i=1;i<maxn;i++){
        pwr[i] = (pwr[i-1] * P)%MOD;
        inv[i] = (inv[i-1] * I)%MOD;
    }
    scanf("%s", s+1);
    int len = strlen(s+1);
    scanf("%s", t+1);
    int n = strlen(t+1);
    for(int i=1;i<=n;i++){
        h[i] = (h[i-1] + (t[i]-'a'+1)*pwr[i-1])%MOD;
    }
    for(int i=1;i<=len;i++){
        cnt[s[i] - '0']++;
    }
    int a = 0, b = 1;
    if(cnt[1]>cnt[0]) swap(a,b);
    int ans = 0;
    for(int lenA=1;lenA<=n;lenA++){
        if(lenA*cnt[a]>n || n-lenA*cnt[a]<cnt[b])
            break;
        int rem = n-lenA*cnt[a];
        if(rem%cnt[b]!=0) continue;
        int lenB = rem/cnt[b];
        ll A = -1, B = -1;
        bool ok = 1;
        int pos = 1;
        for(int j = 1;j<=len;j++){
            if(A!=-1 && B!=-1 && A==B){
                ok=0;
                break;
            }
            if(s[j]-'0'==a){
                ll cur = Hash(pos, pos+lenA-1);
                if(A==-1)
                    A = cur;
                else if(A!=cur){
                    ok=0;
                    break;
                }
                pos+=lenA;
            }
            else
            {
                ll cur = Hash(pos, pos+lenB-1);
                if(B==-1)
                    B = cur;
                else if(B!=cur){
                    ok=0;
                    break;
                }
                pos+=lenB;
            }
        }
        if(A!=-1 && B!=-1 && A==B)
            ok=0;
        if(ok) ans++;
    }
    printf("%d\n", ans);
    return 0;
}
