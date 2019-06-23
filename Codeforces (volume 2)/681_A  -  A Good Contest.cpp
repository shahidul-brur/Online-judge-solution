#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>
#define vii vector<pair<int, int> >
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(i=a;i<=b;i++)
#define Fr(i, b, a) for(i=b;i>=a;i--)
#define eps 1e-6
#define pi acos(-1)
#define mp make_pair
#define mem(a, b) memset(a, b, sizeof(a))

int main()
{
    //freopen("in.txt", "r", stdin);
    int n, y=0,i, j, b, a;
    string name;
    cin>>n;
    F(i, 0, n-1)
    {
        cin>>name>>b>>a;
        if(b>=2400 && a>b)
            y=1;
    }
    if(y==1)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}

