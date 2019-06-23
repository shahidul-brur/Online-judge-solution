#include <bits/stdc++.h>
using namespace std ;

const int N = 101 ;

typedef long long ll ;

ll dp[N][N][N] ;
ll a[N] ;

string s ;
int n ;

ll call(int lft , int rgt , int pre_len) {
    if (lft > rgt) return 0;
    if (lft == rgt) {
        return a[pre_len+1];
    }
    if (dp[lft][rgt][pre_len] != -1) return dp[lft][rgt][pre_len];
    ll ans = call(lft + 1 , rgt , 0) + a[pre_len+1];
    for(int nxt = lft + 1 ; nxt <= rgt ; nxt++) {
        if (s[nxt] == s[lft]) {
            ans = max(ans , call(lft+1,nxt-1,0) + call(nxt,rgt,pre_len+1));
        }
    }
    return dp[lft][rgt][pre_len] = ans ;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    memset(dp , -1 , sizeof dp);

    cin >> n ;
    cin >> s ;

    for(int i = 1 ; i <= n ; i++) {
        cin >> a[i] ;
    }

    ll ans = call(0,n-1,0) ;
    cout << ans ;
}