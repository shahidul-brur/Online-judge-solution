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
int cnt[28];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n; string s; cin>>n; cin>>s;
    f0(i,n)
    {
        cnt[s[i]-'a']++;
    }
//    set<ii> st;
//    f0(i,26){
//        if(cnt[i]>0)
//            st.insert(mp(cnt[i], i));
//    }
//    if(st.size()==1)
//    {
//        cout << s << "\n";
//        return 0;
//    }
//    int a, ca=0, b, cb=0;
    string ans;
    f0(i,26)
     f0(j,cnt[i]) ans+=(char)(i+'a');
    
//    while(1)
//    {
//        if(ca>0)
//        {
//            ans+=(char)(a+'a');
//            --ca;
//        }
//        else
//        {
//            if(st.size()==0)
//            {
//                while(cb>0){
//                    ans+=(char)(b+'a');
//                    --cb;
//                }
//                break;
//            }
//            else
//            {
//                ii p = *st.rbegin();
//                st.erase(p);
//                a = p.ss;
//                ans+=(char)(a+'a');
//                ca = p.ff-1;
//            }
//        }
//        
//        if(cb>0)
//        {
//            ans+=(char)(b+'a');
//            --cb;
//        }
//        else
//        {
//            if(st.size()==0)
//            {
//                while(ca>0){
//                    ans+=(char)(a+'a');
//                    --ca;
//                }
//                break;
//            }
//            else
//            {
//                ii p = *st.rbegin();
//                st.erase(p);
//                b = p.ss;
//                ans+=(char)(b+'a');
//                cb = p.ff-1;
//            }
//        }
//    }
    cout << ans;
    return 0;
}


