#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define mp make_pair
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int =b;i>=a;i--)
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
    int g[6], n, cnt=0, a;
    
    while(cin>>n)
    {
        F(i, 1, 4)
            g[i]=0;
        cnt = 0;
        
        F(i, 1, n)
        {
            cin>>a;
            g[a]++;
        }

        cnt+=g[4];

        int m;
        
        m = min(g[3], g[1]);
        cnt+=m;
        g[3]-=m;
        g[1]-=m;
        
        if(g[3]>0)
            cnt+=g[3];
        
        cnt+=g[2]/2;
        g[2]=g[2]%2;
        
        if(g[2]==1)
        {
            cnt++;
            g[1]-=2;
            
        }
        
        if(g[1]>0)
        {
            cnt+=g[1]/4;
            if(g[1]%4!=0)
                cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}

