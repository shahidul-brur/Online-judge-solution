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
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, cnt, cut[10005], n, c[10005];
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mem(c, 0);
        F(i, 1, n)
        {
            cin>>cut[i];
        }
        cin>>s;
        int len=s.length();
        cnt=0;
        F(i, 1, n)
        {
            map<char, int> m1, m2;
            for(int j=cut[i]-1;j>=0;j--)
            {
                m1[s[j]]=1;
                if(c[j]==1)
                    break;
            }
            for(int j=cut[i];j<len;j++)
            {
                if(c[j]==1)
                    break;
                m2[s[j]]=1;
            }
            
            c[cut[i]]=1;
            
            for(char ch = 'a';ch<='z';ch++)
                cnt+=abs(m1[ch]-m2[ch]);
        }
        cout << cnt << "\n";
    }
    return 0;
}

