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
const int MX = 100005;
int a[MX], ans[MX], cnt[MX], block_size, cur_ans, n;
pair<ii, int> queries[MX];
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
    int x = a[idx];
    if(cnt[x]==x)
        cur_ans--;
    cnt[x]++;
    if(cnt[x]==x)
        cur_ans++;
}
void del(int idx)
{
    int x = a[idx];
    if(cnt[x]==x)
        cur_ans--;
    cnt[x]--;
    if(cnt[x]==x)
        cur_ans++;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q, l, r, curL, curR;
    cin>>n>>q;
    block_size = 450;
    f(i, 0, n-1) 
    {
        cin>>a[i];
        if(a[i]>n)
            a[i] = n+1;
    }
    f(i, 0, q-1)
    {
        cin>>l>>r;
        l--;
        r--;
        queries[i].ff.ff = l;
        queries[i].ff.ss = r;
        queries[i].ss = i;
    }
    
    sort(queries, queries+q, cmp);
    
    curL = 0;
    curR = -1;
    cur_ans = 0;
    f(i, 0, q-1)
    {
        l = queries[i].ff.ff;
        r = queries[i].ff.ss;
        int idx = queries[i].ss;
        
        while(curR<r)
            add(++curR);
        while(curR>r)
            del(curR--);
        while(curL<l)
            del(curL++);
        while(curL>l)
            add(--curL);
        ans[idx] = cur_ans;
    }
    f(i, 0, q-1)
        cout << ans[i] << "\n";
    return 0;
}
