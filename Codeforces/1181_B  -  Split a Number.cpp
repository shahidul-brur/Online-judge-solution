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

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;
int n;
string s;
string mx;
string cal(int m)
{
    if(m<0 || m>=n) return mx;
    if(s[m]=='0')
    {
        int x = m, y = m;
        while(x>=0 && s[x]=='0') x--;
        while(y<n && s[y]=='0') y++;
        string r1 = cal(x);
        string r2 = cal(y);
        if(r1<r2) return r1;
        else return r2;
    }
    string a, b, res;
    f0(i,m)
    {
        a+=s[i];
    }
    if(a[m]=='0'){
        while(a.back()=='0'){
            b = "0" + b;
            a.pop_back();
        }
        b = a.back();
        a.pop_back();
    }
    f2(i,m,n-1)
        b+=s[i];
    char c = 0;
    if(a.size()==0 || b.size()==0) return mx;
    //cout << m << ": " << a << " " << b << " => ";
    while(a.size()>0 || b.size()>0){
        int s = c;
        if(a.size()>0) s+=a.back()-'0';
        if(b.size()>0) s+=b.back()-'0';
        if(s>=10) c = 1, s = s-10;
        else c=0;
        res+=s+'0';
        if(a.size()>0) a.pop_back(); 
        if(b.size()>0) b.pop_back();
    }
    if(c>0)
        res +=c+'0';
    while(res.size()<=n+1) res+="0";
    reverse(all(res));
    //cout << res<< "\n";
    return res;
}
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>n;
    cin>>s;
    f0(i,n+3) mx+="9";
    int m = n/2;
    string res = mx;
    //cout << "here\n";
    f2(i,m-3,m+3){
        string cur = cal(i);
        if(cur<res) res = cur;
    }
    int i = 0;
    while(i<res.size() && res[i]=='0') i++;
    while(i<res.size()) cout << res[i], i++;
    return 0;
}
