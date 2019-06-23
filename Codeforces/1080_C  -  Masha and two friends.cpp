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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        ll row, col;
        cin>>row>>col;
        
        ll black, white;
        
        white = ((row+1)/2) * ((col+1)/2);
        white += (row/2) * (col/2);
        
        black = ((row)/2) * ((col+1)/2);
        black += ((row+1)/2) * (col/2);
        //cout << white << " " << black << " => ";
        
        ll x[10], y[10];
        f1(i,4) cin>>x[i]>>y[i];
        
        ll rw = abs(x[2]-x[1])+1;
        ll cw = abs(y[2]-y[1])+1;
        if((x[1]+y[1])%2==0){ // w
            white += ((rw)/2) * ((cw+1)/2);
            white += ((rw+1)/2) * (cw/2);
            
            black-=((rw)/2) * ((cw+1)/2);
            black-=((rw+1)/2) * (cw/2);
        }
        else // b
        {
            white += ((rw+1)/2) * ((cw+1)/2);
            white += (rw/2) * (cw/2);
            black-=((rw+1)/2) * ((cw+1)/2);
            black-=(rw/2) * (cw/2);
        }
        
        rw = abs(x[4]-x[3])+1;
        cw = abs(y[4]-y[3])+1;
        if((x[3]+y[3])%2==0){ // w
            black += ((rw+1)/2) * ((cw+1)/2);
            black += (rw/2) * (cw/2);
            white-=((rw+1)/2) * ((cw+1)/2);
            white-=(rw/2) * (cw/2);;
        }
        else // b
        {
            black += ((rw)/2) * ((cw+1)/2);
            black += ((rw+1)/2) * (cw/2);
            white-= ((rw)/2) * ((cw+1)/2);
            white-= ((rw+1)/2) * (cw/2);
        }
        //cout << white << " " << black << " => ";
        
        ll x5 = max(x[1], x[3]);
        ll y5 = max(y[1], y[3]);
        
        ll x6 = min(x[2], x[4]);
        ll y6 = min(y[2], y[4]);
        
        if(x5<=x6 && y5<=y6){
            rw = abs(x5-x6)+1;
            cw = abs(y6-y5)+1;
            if((x5+y5)%2==0){ // w
                white -= ((rw)/2) * ((cw+1)/2);
                white -= ((rw+1)/2) * (cw/2);
                black+=((rw)/2) * ((cw+1)/2);
                black+=((rw+1)/2) * (cw/2);
            }
            else // b
            {
                white -= ((rw+1)/2) * ((cw+1)/2);
                white -= (rw/2) * (cw/2);
                black+=((rw+1)/2) * ((cw+1)/2);
                black+=(rw/2) * (cw/2);
            }
        }
        
        cout << white << " " << black << "\n";
    }
    return 0;
}
