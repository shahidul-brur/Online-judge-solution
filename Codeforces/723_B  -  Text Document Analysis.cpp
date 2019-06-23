/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul2009         |
|                                   |
\*=================================*/

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
#define mod 1000000007
#define N 100000
string s;
int in, mx, n;
int cntW(int f)
{
    int i, j, k, cnt=0;
    for(j=f;j<n && s[j]!=')';j++)
    {
        if((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z'))
        {
            cnt++;
            //cout << j << " - \n";
            for(k=j+1;;k++)
            {
                if(k==n || s[k]=='_' || s[k]==')')
                {
                    j = k;
                    //cout << " - " << k << "\n";
                    break;
                }
            }
        }
        if(s[j]==')' || j==n)
            break;
    }
    in+=cnt;
    return j;
}
int main()
{
   // freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, i, j, k;
    
    
    while(cin>>n)
    {
        cin>>s;
        in = mx = 0;
        for(i=0;i<n;)
        {
            //cout << i << "\n";
            if(s[i]=='(')
            {
                i = cntW(i+1);
            }
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            {
                int l = 0;
                for(k=i;k<=n;k++)
                {
                    //cout << s[k];
                    if(k==n || s[k]=='(' || s[k]=='_')
                    {
                        i = k;
                        break;
                    }
                    l++;
                }
               // cout << "\n";
                mx = max(l, mx);
            }
            else i++;
        } 
        cout << mx << " " << in << "\n";
    }
    return 0;
}


