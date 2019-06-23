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
#define inf             1e18

ll mini[100002];
ll miniL[1000002];
ll miniR[1000002];

vii bac[1000002], go[1000002];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k;
    cin>>n>>m>>k;
    f(i, 1, m){
        int d, from, to, cost;
        cin>>d>>from>>to>>cost;
        if(from==0)
            bac[d].pb(mp(to, cost));
        else
            go[d].pb(mp(from, cost));
    }
    f(i, 0, 1000000) 
        miniL[i] = miniR[i] = inf;
        
    ll sum = 0;
    f(i, 0, n) mini[i] = -1;
    int cnt = 0;
    f(i, 1, 1000000){
        
        int s = go[i].sz;
        
        f(j, 0, s-1){
            int from = go[i][j].first;
            int cost = go[i][j].second;
            
            if(mini[from]==-1){
                cnt++;
                mini[from] = cost;
                sum+=cost;
            }
            else if(mini[from]>cost){
                sum-=mini[from];
                sum+=cost;
                mini[from] = cost;
            } 
        }
        if(cnt==n)
            miniL[i] = min(miniL[i], sum);
    }
    
    sum = 0;
    f(i, 0, n) mini[i] = -1;
    cnt = 0;
    for(int i = 1000000;i>=1;i--){
        int s = bac[i].sz;
        f(j, 0, s-1){
            int to = bac[i][j].first;
            int cost = bac[i][j].second;
            if(mini[to]==-1){
                cnt++;
                mini[to] = cost;
                sum+=cost;
            }
            else if(mini[to]>cost){
                sum-=mini[to];
                sum+=cost;
                mini[to] = cost;
            } 
        }
        if(cnt==n)
            miniR[i] = min(miniR[i], sum);
    }
    
    ll ans = inf;
    
    for(int i=1;i+k+1<=1000000;i++){
        ans = min(ans, miniL[i] + miniR[i+k+1]);
    }
    if(ans==inf) 
        ans = -1;
    cout << ans << "\n";
    return 0;
}

