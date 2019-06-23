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
    string s1, s2;
    cin>>s1>>s2;
    int n = s1.length();
    F(i, 0, n-1)
    {
        if(isupper(s1[i]))
            s1[i] = tolower(s1[i]);
    }
    F(i, 0, n-1)
    {
        if(isupper(s2[i]))
            s2[i] = tolower(s2[i]);
    }
    if(s1<s2)
        cout << "-1\n";
    else if(s1>s2)
        cout << "1\n";
    else cout << "0\n";
    return 0;
}

