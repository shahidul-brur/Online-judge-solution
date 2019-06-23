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
#define N 100000
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j, a[100];
    while(cin>>n)
    {
        F(i, 1, n)
        {
            cin >>a[i];
        }
        bool y=0;
        if(a[n]==15)
        {
            cout << "DOWN\n";
        }
        else if(a[n]==0)
        {
            cout << "UP\n";
        }
        else if(n==1)
        {
            cout << "-1\n";
        }
        else
        {
            if(a[n]>a[n-1])
            {
                cout << "UP\n";
            }
            else cout << "DOWN\n";
        }
    }
    return 0;
}

