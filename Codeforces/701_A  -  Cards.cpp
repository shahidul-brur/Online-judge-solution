#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
#define mp make_pair
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
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
int p[105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j, n, a[105], sum=0, avg;
    //vi[105];
    cin>>n;
    F(i, 1, n)
    {
        cin>>a[i];
        sum+=a[i];
    }
    avg = sum/(n/2);
    
    F(i, 1, n)
    {
        if(p[i]==0)
        {
            F(j, 1, n)
            {
                if(p[j]==0 && i!=j && a[i]+a[j]==avg)
                {
                    cout << i << " " << j << "\n";
                    p[i]=p[j]=1;
                    break;
                }
            }
        }
    }
    return 0;
}


