/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define ll long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
void preKMP(string sub, int next[])
{
    int m=sub.size();
    next[0] = -1;
    for(int i=1, j=0;i<m;i++, j++)
    {
        while(j>=0 && sub[i]!=sub[j])
            j = next[j];
        next[i] = j;
    }
}
bool isMatched(string str, string sub)
{
    int n=str.size();
    int m=sub.size();
    int next[m+1];
    preKMP(sub, next);
    for(int i=1, j=0;i<n;i++)
    {
        while(j>=0 && str[i]!=sub[j])
            j = next[j];
        j++;
        if(j==m)
            return 1;
    }
    return 0;
}

int countMatch(string str, string sub)
{
    int n=str.size();
    int m=sub.size();
    char key[102];
    strcpy(key, sub.c_str());
    for(int i=m;i>=1;i--)
    {
        key[i] = '\0';
        string now = string(key);
        if(isMatched(str, now))
            return (m-i);
    }
    return m;
}
int main()
{
    //fast;
    in;
    //out;
    int test, i, j, len, word, scroll;
    string s1, s2;
    cin>>test;
    while(test--)
    {
        cin>>len>>word;
        scroll = len;
        cin >> s1;
        for(i=1;i<word;i++)
        {
            cin>>s2;
            //cout << scroll << "\n";
            scroll += countMatch(s1, s2);
            s1 = s2;
        }
        cout<< scroll << "\n";
    }
    return 0;
}