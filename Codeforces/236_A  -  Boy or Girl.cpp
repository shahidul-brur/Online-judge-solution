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
int ch[30];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string s;
    cin>>s;
    int n = s.length();
    
    F(i, 0, n-1) ch[s[i]-'a']=1;
    
    int cnt=0;
    F(i, 0, 25) cnt+=ch[i];
    if(cnt%2==0)
        cout << "CHAT WITH HER!\n";
    else cout << "IGNORE HIM!\n";
    return 0;
}

