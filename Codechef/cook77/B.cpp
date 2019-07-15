/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
| Blog: shahidul-brur.blogspot.com  |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define vi       vector<int>
#define pii      pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define ll              long long
#define ull             unsinged long long
#define mod             1000000007
#define N               100005
#define inf             1e9
int root;
int trie[N][3], sizT=0; //initially have 0, root = 1
int a[N], k;
void insertTrie(int n) 
{
    int v = root;
    for (int i = 0; (1<<i) <= n; i++) 
    {
        int b;
        if(n&(1<<i)>0)
            b=1;
        else b = 0;
        if (trie[v][b] == 0)
            trie[v][b] = ++sizT;
        v = trie[v][b];
    }
}
void queryTrie(int n)
{
    int v = root;
    for (int i = 0; (1<<i) <= n; i++) 
    {
        int b;
        if(n&(1<<i)>0)
            b=1;
        else b = 0;
        if (trie[v][b] == 0) 
            return 0;
        v = trie[v][b];
    }
    return 1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        rep1(i, n)
            trie[i][0] = trie[i][1] = 0;
        int p = 0;
        root = 1;
        trie[root][0] = 1;
        sizT=1;
        rep(i, n)
        {
            cin>>a[i];
        }
    }
    return 0;
}

