#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define pb push_back
#define all(a)  a.begin(), a.end()
#define f1(i,b) for(int i=1;i<=(b);i++)
const int maxn = (int)2e5+5;
int a[100005];
int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mx = -1, beg = 0, en;
        bool ok=1;
        f1(i,n){
            cin>>a[i];
            mx=max(mx, a[i]);
            if(a[i]!=-1){
                en = i;
                if(!beg) beg=i;
            }
        }
        if(n==1 || mx==-1 || beg==en){
            cout << "inf\n";
            continue;
        }
        
        for(int i=en;i>beg;i--){
            if(a[i]==-1) continue;
            if(a[i]==1 && !(a[i-1]==-1 || a[i-1]==mx)){
                ok = 0;
                break;
            }
            if(a[i]>1){
                if(a[i-1]==-1) a[i-1] = a[i]-1;
                if(a[i-1]!=a[i]-1){
                    ok=0;
                    break;
                }
            }
        }
        for(int i=beg;i<=en;i++){
            if(a[i]==-1) continue;
            
            if(a[i]==1 && !(i==beg || a[i-1]==-1 || a[i-1]==mx)){
                ok=0;
                break;
            }
            if(a[i]==mx && !(i==en || a[i+1]==1 || a[i+1]==-1)){
                ok=0;
                break;
            }
            if(a[i]<mx){
                if(i==en) continue;
                if(a[i+1]==-1) a[i+1] = a[i]+1;
                if(a[i+1]!=a[i]+1){
                    ok=0;
                    break;
                }
            }
        }
        if(!ok){
            cout << "impossible\n";
            continue;
        }
        set<int> gp;
        for(int i=beg;i<en;i++){
            
            if(a[i]!=mx) continue;
            int g = 0;
            while(i+1<=en && a[i+1]==-1){
                g++;
                i++;
            }
            gp.insert(g);
        }
        if(gp.size()==0){
            cout << "inf\n";
            continue;
        }
        int gcd = 0;
        for(int g:gp){
            gcd = __gcd(gcd, mx+g);
        }
        if(gcd<mx){
            cout << "impossible\n";
        }
        else {
            cout << gcd << "\n";
        }
    }
    return 0;
}

