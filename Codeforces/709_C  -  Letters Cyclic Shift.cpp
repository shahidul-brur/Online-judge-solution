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
        n = s.length();
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='a')
            {
                s[i]--;
                f=1;
                for(int j=i+1;j<n;j++)
                {
                    if(s[j]!='a')
                        s[j]--;
                    else break;
                }
                break;
            }
        }
        if(f==0)
           s[n-1] = 'z';
        cout << s << "\n";
    }
    return 0;
}