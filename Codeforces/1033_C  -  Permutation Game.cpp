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
int a[maxn];
int ans[maxn];
int pos[maxn];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    cin>>n;
    f1(i,n)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    
    fr(i,n,1)
    {
        int idx = pos[i];
        if(idx+i>n && idx-i<1)
        {
            ans[idx] = 0;
            continue;
        }
        int ok = 0;
        //cout << i << ":\n";
        for(int j = idx+i;j<=n;j+=i){
           // cout << j << ", ";
            if(a[j]>i && ans[j]==0){
                ok=1;
                break;
            }
        }
        //cout << "\n";
        if(ok){
            ans[idx] = 1;
            continue;
        }
        
        for(int j = idx-i;j>=1;j-=i){
            //cout << j << ", ";
            if(a[j]>i && ans[j]==0){
                ok=1;
                break;
            }
        }
        //cout << "\n";
        if(ok){
            ans[idx] = 1;
            continue;
        }
    }
    f1(i,n)
    {
        if(ans[i]) 
            cout << "A";
        else 
            cout << "B";
    }
    cout << "\n";
    return 0;
}


