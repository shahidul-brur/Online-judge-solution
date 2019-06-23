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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, i, j, k;
    string s1, s2;
    while(cin>>s1)
   {
       
       
   n = s1.size();
    int cnt = 0;
    char c = 'a';
    for(i=0;i<n;i++)
    {
        int add = min(abs(c - s1[i]), min(abs(c-'z')+s1[i]-'a'+1, abs(c-'a')+abs('z' - s1[i])+1));
        cnt +=add;
       // cout << add << "\n";
        c = s1[i];
    }
    cout << cnt << "\n";
   }
    return 0;
}


