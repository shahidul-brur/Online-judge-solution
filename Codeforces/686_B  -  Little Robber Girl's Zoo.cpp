#include<bits/stdc++.h>
using namespace std;

// ----------- define -----------------------------------
#define pb push_back
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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, j, cnt, x[20005], y[200005], a[105], l, r;
    while(cin>>n)
    {
        F(i, 0, n-1)
        {
            cin>>a[i];
        }
        bool s = 0;
        cnt = 0;
        while(s==0)
        {
            bool d = 0;
            for(i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1])
                {
                    d = 1;
                    l = i;
                    r = i+1;
                    for(j=i+2;j<n-1;j+=2)
                    {   
                        if(a[j]<=a[j+1])
                            break;
                        r = j+1;
                    }
                    x[cnt] = l+1;
                    y[cnt] = r+1;
                    cnt++;
                    break;
                }
            }
            if(d)
                for(i=l;i<r;i+=2)
                {
                    int tmp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = tmp;
                }
            bool st = 1;
            /*
            for(i=0;i<n;i++)
            {
                cout << a[i] << " ";
            }
            cout << "\n\n";
            */
            for(i=0;i<n-1;i++)
            {
                if(a[i]>a[i+1])
                {
                    st = 0;
                    break;
                }
            }
            
            if(st==1)
            {
                s = 1;
                break;
            }
        }
        for(i=0;i<cnt;i++)
        {
            cout << x[i] << " " << y[i] << "\n";
        }
    }
    return 0;
}

