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
   // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int m=0, c=0, n, a, b;
    while(cin>>n)
    {
        m=c=0;
        F(i, 1, n)
        {
            cin>>a>>b;
            if(a>b)
                m++;
            else if(b>a) c++;
        }
        if(m>c)
            cout << "Mishka\n";
        else if(c>m)
            cout << "Chris\n";
        else cout << "Friendship is magic!^^\n";
    }
    return 0;
}

