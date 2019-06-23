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
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j;
    string s;
    while(cin>>s)
    {
        if(s.length()%2==1)
            cout << "-1\n";
        else
        {
            int siz = s.length();
            int l=0, r=0, u=0, d=0;
            F(i, 0, siz-1)
            {
                if(s[i]=='L')
                    l++;
                else if(s[i]=='R')
                    r++;
                else if(s[i]=='U')
                    u++;
                else if(s[i]=='D')
                    d++;
            }
            if(l==r)
                cout << abs(u-d)/2 << "\n";
            else if(u==d)
                cout << abs(l-r)/2 << "\n";
            else
            {
                int dif = (abs(l-r) + abs(u-d))/2;
                cout << dif << "\n";
            }
        }
    }
    return 0;
}

