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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define f(i, a, b)      for(int i=(a);i<=(b);i++)

const int MAX = 1000002;
const int mod = 1000000007;
int cnt[MAX+2];
int z[MAX+2];
void z_function(char *s) {
    int n = strlen(s);
    z[0] = 0;
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        else z[i] = 0;
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    z[0] = 1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    char s[MAX];
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    z_function(s);
    int len = strlen(s);
    int l = -1, r = -1;
    f(i, 1, m)
    {
        int p;
        scanf("%d", &p);;
        --p;
        if(p<=r){
            if(z[p-l]<r-p+1) { printf("0\n"); return 0;}
        }
        cnt[p]++;
        cnt[p+len]--;
        l = p, r = p+len-1;
    }
    ll ans = 1LL;
    f(i, 0, n-1)
    {
        if(i>0)
            cnt[i]+=cnt[i-1];
        if(cnt[i]==0)
        {
            ans = ans*26;
            ans%=mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
