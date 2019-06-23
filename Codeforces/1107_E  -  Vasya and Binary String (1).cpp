#include <bits/stdc++.h>
using namespace std ;

const int N = 101 ;

typedef long long ll ;

ll dp[N][N][N] ;
ll a[N] ;

string s ;
int n ;

ll call(int lft , int rgt , int len) {
    if (lft > rgt) return 0;
    if (lft == rgt) {
        return a[len];
    }
    if (dp[lft][rgt][len] != -1) return dp[lft][rgt][len];
    ll ans = call(lft + 1 , rgt , 1) + a[len];
    for(int nxt = lft + 1 ; nxt <= rgt ; nxt++) {
        if (s[nxt] == s[lft]) {
            ans = max(ans , call(lft+1,nxt-1,1) + call(nxt,rgt,len+1));
        }
    }
    return dp[lft][rgt][len] = ans ;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    memset(dp , -1 , sizeof dp);

    cin >> n ;
    cin >> s ;

    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
    }

    ll ans = call(0,n-1,1) ;
    cout << ans ;
}