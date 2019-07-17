
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
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};

const double pi = acos(-1.0);
const double eps = 1e-6;
const int mod = (int)1e9+7;
const int maxn = (int)2e5+5;
const int logn = 20;
class Solution {
public:
    bool is_operator(char c){
        return c=='!' || c=='|' || c=='&';
    }
    
    bool eval(string expr, char op, int &idx){
        bool res = 1;
        int i = idx;
        if(op=='|') res = 0;
        while(idx<expr.size()){
            char ch = expr[idx];
            bool cur;
            if(is_operator(ch)){
                idx+=2;
                int p = idx;
                cur = eval(expr, ch, idx);
            }
            else if(ch=='t'){
                cur = 1;
                idx+=1;
            }
            else if(ch=='f'){
                cur = 0;
                idx+=1;
            }
            else if(ch==')'){
                idx+=1;
                break;
            }
            else if(ch==','){
                idx+=1;
                continue;
            }
            if(op=='!') res = !cur;
            else if(op=='&')
                res &= cur;
            else if(op=='|')
                res|=cur;
        }
        return res;
    }
    bool parseBoolExpr(string expr) {
        int idx = 2;
        bool res = eval(expr, expr[0], idx);
        return res;
    }
};
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    Solution s;
    string expr = "!(&(!(t),&(f),|(f)))";
    cout << expr << "\n";
    cout << s.parseBoolExpr(expr) << "\n";
    return 0;
}
