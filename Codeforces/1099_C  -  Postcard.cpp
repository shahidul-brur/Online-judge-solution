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
bool del[250];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s;
    int k;
    cin>>s;
    cin>>k;
    int n = s.size();
    int c = n;
    bool star = 0, wh=0;
    f0(i,n){
        if(s[i]=='*' || s[i]=='?') c--;
        if(s[i]=='*') star=1;
        if(s[i]=='?') wh=1;
    }

    if(k>=c){
        if(k>c && star==0){
            cout << "Impossible";
            return 0;
        }
        bool ok=0;
        f0(i,n){

            if(s[i]=='?') continue;
            if(s[i]=='*' && !ok){
                f0(j,k-c) cout << s[i-1];
                ok=1;
            }
            else if(islower(s[i])) cout << s[i];
        }
        return 0;
    }
    if(k<c){
        if(wh==0 && star==0){
            cout << "Impossible";
            return 0;
        }
        fr(i,n-1,0){
            if(s[i]=='?' || s[i]=='*')
            {
                del[i] = 1;
                if(c>k && i-1>=0 && islower(s[i-1])){
                    del[i-1]=1;
                    --c;
                }
            }
        }
        if(c!=k){
            cout << "Impossible";
            return 0;
        }
        f0(i,n) if(!del[i] && islower(s[i])) cout << s[i];
    }
    return 0;
}
