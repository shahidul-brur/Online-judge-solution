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
int bsiz;
int ara[MX], cnt[320][MX], n;
deque<int> block[320];
void preprocess()
{
    mem(cnt, 0);
    f(i, 0, n-1)
    {
        cnt[i/bsiz][ara[i]]++;
        block[i/bsiz].pb(ara[i]);
    }
}
void update(int l, int r)
{
    int l_block = l/bsiz;
    int r_block = r/bsiz;
    //cout << "here\n";
    if(l_block==r_block)
    {
        int bid = l_block;
        int r_idx = r - bid*bsiz;
        int l_idx = l - bid*bsiz;
        int r_val = block[bid][r_idx];
        block[bid].erase(block[bid].begin()+r_idx);
        block[bid].insert(block[bid].begin()+l_idx, r_val);
    }
    else
    {
        int r_idx = r - r_block*bsiz;
        int l_idx = l - l_block*bsiz;
        int r_val = block[r_block][r_idx];
        block[r_block].erase(block[r_block].begin()+r_idx);
        block[l_block].insert(block[l_block].begin()+l_idx, r_val);
        cnt[r_block][r_val]--;
        cnt[l_block][r_val]++;
        for(int i = l_block;i<r_block;i++)
        {
            int val = block[i].back();
            block[i].pop_back();
            block[i+1].push_front(val);
            cnt[i][val]--;
            cnt[i+1][val]++;
        }
    }
}
int query(int l, int r, int k)
{
    int l_block = l/bsiz;
    int r_block = r/bsiz;
    
    if(l_block==r_block)
    {
        int ret = 0;
        for(int i = l;i<=r;i++)
            if(block[l_block][i-l_block*bsiz]==k)
                ret++;
        return ret;
    }
    else
    {
        int left, mid, right;
        
        left = 0;
        for(int i = l;i<(l_block+1)*bsiz;i++)
            if(block[l_block][i-l_block*bsiz]==k)
                left++;
        
        mid = 0;
        for(int i = l_block+1;i<r_block;i++)
            mid+=cnt[i][k];
        
        right = 0;
        for(int i = r_block*bsiz;i<=r;i++)
            if(block[r_block][i-r_block*bsiz]==k)
                right++;
        return (left+mid+right);
    }
}


void print()
{
    for(int i = 0;i<n/bsiz + (n%bsiz>0);i++)
    {
        cout << "BLOCK " << i << " : ";
        for(int j = 0;j<block[0].size();j++)
            cout << block[i][j] << ", ";
        cout << "\n";
    }
    cout << "===========\n";
}


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n;
    bsiz = sqrt(n);
    if(bsiz*bsiz<n)
        ++bsiz;
    
    f(i, 0, n-1)
        cin>>ara[i];
    
    preprocess();
    
    int q;
    cin>>q;
    int ans = 0;
    
    while(q--)
    {
        //print();
        int typ, l, r, k;
        cin>>typ>>l>>r;
        
        l = (l+ans-1)%n;
        r = (r+ans-1)%n;
        
        if(r<l)
            swap(l, r);
        
        if(typ==1)
        {
            
            //cout << "here\n";
            update(l, r);
        }
        else
        {
            cin>>k;
            k=(k+ans-1)%n +1;
            ans = query(l, r, k);
            //cout << l << ", " << r << " -> " << " ans = ";
            cout << ans << "\n";
        }
    }
    return 0;
}