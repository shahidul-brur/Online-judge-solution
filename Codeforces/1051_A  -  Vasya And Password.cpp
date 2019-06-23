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
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.size();
        int lo=0, up=0,dg=0;
        f0(i,n) {
            if(islower(s[i])) lo++;
            else if(isupper(s[i])) up++;
            else if(isdigit(s[i])) dg++;
        }
        int need = 0;
        if(!lo) need++; 
        if(!up) need++; 
        if(!dg) need++;
        if(need==0){
            cout << s << "\n";
            continue;
        }
        f0(i,n)
        {
            if(need==1){
                if((islower(s[i]) && lo>1) || (isupper(s[i]) && up>1) || (isdigit(s[i]) && dg>1) )
                {
                    if(lo==0) s[i] = 'a';
                    if(up==0) s[i] = 'A';
                    if(dg==0) s[i] = '1';
                    break;
                }
            }
            else
            {
                bool same = 0;
                if(isupper(s[i]) && isupper(s[i+1]) || islower(s[i]) && islower(s[i+1])
                   || isdigit(s[i]) && isdigit(s[i+1])) same = 1;
                if(same){
                    //cout << "#\n";
                    if((islower(s[i]) && lo>2) || (isupper(s[i]) && up>2) || (isdigit(s[i]) && dg>2) )
                    {
                        if(lo==0) s[i] = 'a', lo++;
                        else if(up==0) s[i] = 'A', up++;
                        else if(dg==0) s[i] = '1', dg++;
                        
                        if(lo==0) s[i+1] = 'a', lo++;
                        else if(up==0) s[i+1] = 'A', up++;
                        else if(dg==0) s[i+1] = '1', dg++;
                        break;
                    }
                }
                else
                {
                    if(((islower(s[i]) && lo>1) || (isupper(s[i]) && up>1) || (isdigit(s[i]) && dg>1))
                       && (islower(s[i+1]) && lo>1) || (isupper(s[i+1]) && up>1) || (isdigit(s[i+1]) && dg>1)) 
                    {
                        if(lo==0) s[i] = 'a', lo++;
                        else if(up==0) s[i] = 'A', up++;
                        else if(dg==0) s[i] = '1', dg++;
                        
                        if(lo==0) s[i+1] = 'a', lo++;
                        else if(up==0) s[i+1] = 'A', up++;
                        else if(dg==0) s[i+1] = '1', dg++;
                        break;
                    }
                }
            }
        }
        cout << s << "\n";
    }
    return 0;
}


