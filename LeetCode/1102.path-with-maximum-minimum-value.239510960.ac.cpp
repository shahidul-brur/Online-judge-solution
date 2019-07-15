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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;
const int LOGN = 20;

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int R = A.size();
        int C = A[0].size();
        priority_queue<pair<int, pair<int,int> > > pq; // cost, node
	    bool taken[103][103]; memset(taken, 0, sizeof(taken));
        pq.push(make_pair(A[0][0], make_pair(0,0)));

        int minimum_cost = 1000000005;

        while(!pq.empty()){
            pair<int, pair<int,int> > top = pq.top(); pq.pop();
            int cost = top.first,  r = top.ss.ff, c = top.ss.ss;
            if(!taken[r][c]){
                taken[r][c] = 1;
                minimum_cost=min(minimum_cost, cost);
                if(r==R-1 && c==C-1) return minimum_cost;
                for(int i = 0;i<4;i++){
                    int nr = r+dx[i];
                    int nc = c+dy[i];
                    if(nr>=R || nr<0 || nc<0 || nc>=C || taken[nr][nc]) continue;
                    pq.push(mp(A[nr][nc], mp(nr,nc)));
                }
            }
        }
        return -1;
    }
};
