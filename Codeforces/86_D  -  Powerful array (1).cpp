/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MX = 200005;
int a[MX],cnt[1000005];
int n, q, block_size;
ll cur_ans, ans[MX];
vector<pair<ii, int> > queries;
bool cmp(pair<ii, int> a, pair<ii, int> b)
{
    int block_a = a.ff.ff/block_size;
    int block_b = b.ff.ff/block_size;
    if(block_a==block_b)
        return a.ff.ss<b.ff.ss;
    return block_a<block_b;
}
void add(int idx)
{
    ll x = a[idx];
    cur_ans-=1LL*cnt[x]*cnt[x]*x;
    cnt[x]++;
    cur_ans+=1LL*cnt[x]*cnt[x]*x;
}
void del(int idx)
{
    ll x = a[idx];
    cur_ans-=1LL*cnt[x]*cnt[x]*x;
    cnt[x]--;
    cur_ans+=1LL*cnt[x]*cnt[x]*x;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int L, R, cur_L=0, cur_R=-1, idx;
    cur_ans = 0LL;
    cin>>n>>q;
    block_size = 450;
    f(i, 0, n-1) cin>>a[i];
    
    f(i, 0, q-1)
    {
        cin>>L>>R;
        L--;
        R--;
        queries.pb(mp(mp(L, R), i));
    }
    sort(all(queries), cmp);
        
    f(i, 0, q-1)
    {
        L = queries[i].ff.ff;
        R = queries[i].ff.ss;
        //cout << L << " " << R << " -> " << cur_L << " " << cur_R << "\n" ;
        idx = queries[i].ss;
        while(cur_R<R)
            add(++cur_R);
        while(cur_R>R)
            del(cur_R--);
        while(cur_L>L)
            add(--cur_L);
        while(cur_L<L)
            del(cur_L++);
        ans[idx] = cur_ans;
    }
    f(i, 0, q-1)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}
