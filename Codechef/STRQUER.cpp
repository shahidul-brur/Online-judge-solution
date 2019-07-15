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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
#define inf             1e9
//             0123456789
const int MX = 100002;
int tem[MX];
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    tem[0] = 0;
    while(t--) {
        int n, q;
        cin>>n>>q;
        f(i, 1, n){
            cin>>tem[i];
        }
        
        int cnt = n;
        while(q--) {
            ll ans;
            int tp, x;
            cin>>tp>>x;
            if(tp==1) {
                tem[++cnt] = x;
            }
            else{
                for(int i = 1; i<=cnt; i++){
                    if(tem[i]==x){
                        for(int j = i;j<cnt;j++)
                            tem[j] = tem[j+1];
                        break;
                    }
                }
                cnt--;
            }
            
            sort(tem+1, tem+cnt+1);
            
            if(cnt==1){
                cout << "0\n";
                continue;
            }
            ll sum = 0LL;
            for(int i = 1; i<=cnt; i++) {
                if(i%2==0)
                    sum+=1LL*abs(tem[i] - tem[i-1]);
            }
            if(cnt%2==1)
                sum+=1LL*abs(tem[cnt] - tem[cnt-1]);
            ans = sum;
            sum=0LL;
            for(int i = 1; i<=cnt; i++) {
                if(i>1 && i%2==1)
                    sum+=1LL*abs(tem[i] - tem[i-1]);
            }
            sum+=1LL*abs(tem[2]-tem[1]);
            if(cnt%2==0)
                sum+=1LL*abs(tem[cnt] - tem[cnt-1]);
            ans = min(sum, ans);
            cout << ans << "\n";
        }
    }
    return 0;
}

