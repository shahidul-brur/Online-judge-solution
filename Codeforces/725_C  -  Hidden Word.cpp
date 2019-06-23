/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;
#define DEBUG(x) cout<<#x<<": "<<x<< "\n"
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
map<char, int> f;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    string s;
    int i, j, k, l;
    while(cin>>s)
    {
        bool r = 0;
        F(i, 0, 25)
        {
            if(s[i]==s[i+1])
            {
                r=1;
                break;
            }
        }
        if(r)
            cout << "Impossible\n";
        else
        {
            char rep;
            char a[3][30];
            int pos1, pos2;
            F(i, 0, 26)
            {
                f[s[i]]++;
                if(f[s[i]]==2)
                {
                    rep = s[i];
                    pos2 = i;
                    for(int j=pos2-1;j>=0;j--)
                    {
                        if(s[j]==rep)
                        {
                            pos1 = j;
                            break;
                        }
                    }
                    break;
                }
            }
            int h = (pos2 - pos1-1)/2;
            l = 12;
            for(i=pos1+h;i>=0 && l>=0;i--)
                a[0][l--] = s[i];
            if(l>=0)
            {
                for(i=26;i>=0 && l>=0;i--)
                    a[0][l--] = s[i];
            }
            l = 12;
            for(i=pos1+h+1;i<=26 && l>=0;i++)
                if(s[i]!=rep)
                    a[1][l--] = s[i];
            if(l>=0)
            {
                for(i=0;i<pos1 && l>=0;i++)
                    if(s[i]!=rep)
                        a[1][l--] = s[i];
            }
            a[0][13] = '\0';
            a[1][13] = '\0';
            cout << a[0] << "\n" << a[1] << "\n";
        }
        f.clear();
    }
    return 0;
}
