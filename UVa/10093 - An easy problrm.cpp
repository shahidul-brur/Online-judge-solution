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
char s[1000005];
int charNum(char c)
{
    int n;
    if(c>='0' && c<='9')
        n = (c - '0');
    else if(c>='A' && c<='Z')
        n = (c - 'A') + 10;
    else if(c>='a' && c<='z')
        n = (c - 'a') + 36;
    return n;
}
int sum()
{
    ll add = 0;
    int len = strlen(s);
    int f = 0;
    if(s[0]=='+' || s[0]=='-')
        f++;
    for(int i=len-1;i>=f;i--)
    {
        add+=(charNum(s[i]));
    }
    return add;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ll n, now, b, i;
    while(cin>>s)
    {
        int len = strlen(s);
        
        ll mx = 0;
        i = 0;
        if(s[i]=='+' || s[i]=='-')
            i++;
        for(;i<len;i++)
        {
            now = charNum(s[i]);
            mx = max(mx, now);
        }
        b = 0;
        if(mx==0)
            mx = 1;
        ll sm = sum();
        for(int i=mx+1;i<=62;i++)
        {
            if(sm%(i-1)==0)
            {
                b = i;
                break;
            }
        }
        if(b==0)
            cout << "such number is impossible!\n";
        else cout << b << "\n";
    }
    return 0;
}

