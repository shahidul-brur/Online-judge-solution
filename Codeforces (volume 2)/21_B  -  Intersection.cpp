/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               1000005
#define inf             1e9

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a[5], b[5];
    rep(i, 3)
        cin>>a[i];
    rep(i, 3)
        cin>>b[i];
    if(a[0]==0 && a[1]==0 && a[2]==0 )
    {
        if(b[0]==0 && b[1]==0 && b[2]!=0)
            cout << "0\n";
        else cout << "-1\n";
    }
    else if(b[0]==0 && b[1]==0 && b[2]==0)
    {
        if(a[0]==0 && a[1]==0 && a[2]!=0)
            cout << "0\n";
        else cout << "-1\n";
    }
    else if(a[0]==0 && a[1]==0 && a[2]!=0 || b[0]==0 && b[1]==0 && b[2]!=0)
        cout << "0\n";
    else if(a[0]==b[0] && a[1]==b[1] && a[2]==b[2])
        cout << "-1\n";
    //0, y
    else if(a[0]==0 && a[1]!=0) // 0x + b1y = c1
    {
        if(b[0]==0 && b[1]!=0) // 0x + b2 = c2
            if(a[1]*b[2] == b[1]*a[2]) // same
                cout << "-1\n";
            else cout << "0\n"; // parallel
        else if(b[0]!=0) // b2x + 0y = c2
            cout << "1\n"; // parallel
        else cout << "0\n";
    }
    //x, 0
    else if(a[0]!=0 && a[1]==0) // a1x + 0y = c1
    {
        if(b[0]!=0 && b[1]==0) // a2x + 0y = c2
            if(a[0]*b[2] == b[0]*a[2]) // same
                cout << "-1\n";
            else cout << "0\n"; // parallel
        else if(b[1]!=0) // 0x + b2y = c2
            cout << "1\n"; // parallel
        else cout << "0\n";
    }
    //0, 0
    else if(a[0]==0 && a[1]==0)
    {
        if(a[0]*b[1]==b[0]*a[1] && a[1]*b[2]==b[1]*a[2])
            cout << "-1\n";
        else if(a[0]*b[1]==b[0]*a[1] && a[1]*b[2]!=b[1]*a[2])
            cout << "0\n";
        else cout << "1\n";
    }
    
    //x, y
    else if(a[0]!=0 && a[1]!=0) // if a1, b1 non zero
    {
        if(a[0]*b[1] == b[0]*a[1] && a[1]*b[2] == b[1]*a[2]) // same
        {
            cout << "-1\n";
        }
        else if(a[0]*b[1] == b[0]*a[1] && a[1]*b[2] != b[1]*a[2]) // parallel
            cout << "0\n";
        else cout << "1\n";
    }
    
    return 0;
}
