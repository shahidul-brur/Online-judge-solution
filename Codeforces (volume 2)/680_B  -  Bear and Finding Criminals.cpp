#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define F(a, b) for(i=a;i<=b;i++)
#define Fr(b, a) for(i=b;i>=a;i--)
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
    int n, a, b[105], i, j, k, cnt;
    while(cin>>n)
    {
        cin>>a;
        for(i=1;i<=n;i++)
            cin>>b[i];
        
        cnt=0;
        for(j=a, k=a;j>=1 || k<=n;j--, k++)
        {
            if(j<=0)
            {
                if(b[k]==1)
                    cnt++;
            }
            else if(k>n)
            {
                if(b[j]==1)
                    cnt++;
            }
            else if(b[j]==1 && b[k]==1)
            {
                if(j==k)
                    cnt++;
                else cnt+=2;
            }
        }
        cout << cnt << "\n";
        fflush(stdout);
        
    }
    return 0;
}

