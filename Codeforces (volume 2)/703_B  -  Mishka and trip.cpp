#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define mp make_pair
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long

// ---------------- typedef ------------------------------
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

// --------------   template ends  ------------------------

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll c[100005], cnt, t;
    c[0]=0;
    int n, k, id[100005];
    while(cin>>n>>k)
    {
        cnt=0;
        t=0;
        F(i, 1, n)
        {
            cin>>c[i];
            cnt+=c[i]*c[i-1];
            t+=c[i];
        }
        cnt+=c[1]*c[n];
        ll cap=0;
        id[0]=-100;
        F(i, 1, k)
        {
            cin>>id[i];
            int nxt = id[i]+1;
            if(nxt>n)
                nxt=1;
            int prev = id[i]-1;
            if(prev<1)
                prev = n;
            ll add = t-c[id[i]]-c[prev] - c[nxt] - cap;
            if(id[i-1]==id[i]-1)
                add+=c[id[i-1]];
                
            if(id[1]==1 && id[i]==n)
                add+=c[1];
                
            cnt+=c[id[i]]*add;
            //cout << c[id[i]]*add << "...\n";
            cap+=c[id[i]];
        }
        cout << cnt << "\n";
    }
    return 0;
}

