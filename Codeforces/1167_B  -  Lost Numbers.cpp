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
bool vis[50], ase[50];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a[7],p,b[6] = {4 , 8, 15, 16, 23, 42}, q[7];
    //f0(i,6) f2(j,i,5) cout << b[i]*b[j] << "\n";
    
    f0(i,6) ase[b[i]]=1;
    printf("? 1 2\n");
    fflush(stdout);
    scanf("%d", &q[1]);
    
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d", &q[2]);
    
    f0(i,6) if(q[1]%b[i]==0 && q[1]/b[i]!=b[i] && ase[q[1]/b[i]] &&  q[2]%b[i]==0 && q[2]/b[i]!=b[i] && ase[q[2]/b[i]]){
        a[2] = b[i];
        break;
    }
    a[1] = q[1]/a[2];
    a[3] = q[2]/a[2];
    f1(i,3) vis[a[i]]=1;
    printf("? 4 5\n");
    fflush(stdout);
    scanf("%d", &q[3]);
    
    printf("? 5 6\n");
    fflush(stdout);
    scanf("%d", &q[4]);
    
    f0(i,6) if(!vis[b[i]] && q[3]%b[i]==0 && q[3]/b[i]!=b[i] && ase[q[3]/b[i]] && !vis[q[3]/b[i]] && q[4]%b[i]==0 && q[4]/b[i]!=b[i] && ase[q[4]/b[i]] && !vis[q[4]/b[i]]){
        a[5] = b[i];
        break;
    }
    a[4] = q[3]/a[5];
    a[6] = q[4]/a[5];
    printf("!");
    f1(i,6)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
    
    return 0;
}
