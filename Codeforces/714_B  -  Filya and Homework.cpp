#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define N 1000000
int a[100005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, typ[10];
    while(cin>>n)
    {
        t=0;
        F(i, 0, n-1)
        {
            cin>>a[i];
            if(t==0)
            {
                typ[t++] = a[i];
            }
            else if(t<=5)
            {
                bool r = 0;
                F(j, 0, t-1)
                {
                    if(typ[j]==a[i])
                    {
                        r = 1;
                        break;
                    }
                }
                if(r==0)
                    typ[t++] = a[i];
            }
        }
        sort(typ, typ+t);
        if(t>3)
        {
            cout << "NO\n";
        }
        else if(t==1)
        {
            cout << "YES\n";
        }
        else if(t==2)
        {
            //if(typ[0]==0 || typ[0]+typ[0] == typ[1])
                cout << "YES\n";
            //else cout << "NO\n";
        }
        else if(t==3)
        {
            bool y = 0;
            //if((typ[0] + typ[0] == typ[1] && typ[1] == typ[2]-typ[0]) || (typ[2] - typ[1]==typ[1] && typ[0]+typ[1]==typ[1]))
                //y=1;
            if((typ[1] - typ[0] == typ[2]-typ[1]) || (typ[2] - typ[1]==typ[1] && typ[0]+typ[1]==typ[1]))
                y=1;
            if(y)
                cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

