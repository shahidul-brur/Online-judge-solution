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
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)
const int maxn = (int)2e5+5;
int a[maxn];
ll s[maxn];
int tree[maxn<<1];
int M;
void add(int pos, int val) // go up
{
    while(pos<=M){
        tree[pos]+=val;
        pos +=(pos & -pos);
    }
}

int cal(int pos) // go down
{
    int sum = 0;
    while(pos>0){
        sum+=tree[pos];
        pos -=(pos&-pos);
    }
    return sum;
}
ll req[maxn];
int cr[maxn], cs[maxn];
vector<pair<ll, ii> > v;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    ll t;
    cin>>n>>t;
    f1(i,n)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        req[i] = t-1+s[i-1];
        v.pb(mp(s[i], mp(i, 1)));
        v.pb(mp(req[i], mp(i, 2)));
    }
    sort(v.begin(),v.end());
    int cur = 1;
    int i = 0, siz = v.size();
    for(i=0;i<siz;i++){
        if(i>0 && v[i].first>v[i-1].first) ++cur;
        if(v[i].ss.ss==1) cs[v[i].ss.first] = cur;
        else cr[v[i].ss.first] = cur;
    }
    M = cur;
    ll ans = 0;
    fr(i,n,1)
    {
        add(cs[i], +1);
        ans+=cal(cr[i]);
    }
    cout << ans;
    return 0;
}
