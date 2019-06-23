/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define ll       long long
#define ull      unsinged long long
#define vi       vector<int>
#define vll      vector<ll>
#define ii       pair<int, int>
#define vii      vector<pair<int, int> >
#define vs       vector<string>
#define vd       vector<double>
#define mii       map<int, int>
#define mli       map<ll, int>
#define msi       map<string, int>

#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define sz              size()
#define all(a)          a.begin(), a.end()
#define f(i, a, b)      for(int i=(a);i<=(b);i++)
#define F(i, a, b)      for(int i=(a);i>=(b);i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
const int MAX = 105;
int m[MAX][MAX];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k, i, j, l;
    while(cin>>n>>k)
    {
        mem(m, 0);
        if(k>n*n)
            cout << "-1\n";
        else
        {
            int cnt = 0, r = k;
            for(i=0;i<n && cnt<k && r>0;i++)
            {
                int need = 2*(n-i-1) + 1;
                if(r>=need)
                {
                    m[i][i] = 1;
                    for(j= i+1;j<n;j++) m[i][j] = 1;
                    for(j= i+1;j<n;j++) m[j][i] = 1;
                    r-=need;
                    cnt+=need;
                }
                else
                {
                    m[i][i] = 1;
                    cnt++;
                    r--;
                    int p = r/2, c;
                    for(j= i+1, c=0;j<n && c<p;j++) m[i][j] = 1, c++;
                    for(j= i+1, c=0;j<n && c<p;j++) m[j][i] = 1, c++;
                    
                    r-=(p*2);
                    cnt+=(p*2);
                }
            }
            
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(j>0) cout << " ";
                    cout << m[i][j];
                }
                cout << "\n";
            }
        }
    }
    return 0;
}



