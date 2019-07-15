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
int dx[] = {1, -1, 0};
int dy[] = {0, 0, 1};
const int MX = 100005;
char s[3][505];
int n, tot;
bool v[3][505];
void visit(int r, int c)
{
    v[r][c] = 1;
    
    tot++;
    f(i, 0, 2)
    {
        int nr = r+dx[i];
        int nc = c+dy[i];
        if(nr>=0 && nr<=1 && nc>=0 && nc<n && v[nr][nc]==0 && s[nr][nc]=='#')
        {
            visit(nr, nc);
            return;
        }
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, has;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s[0]>>s[1];
        has=0;
        f(i, 0, 1) f(j, 0, n-1)
            if(s[i][j]=='#' && v[i][j]==0)
                has++;
                
        int found=0;
        //cout << has << "\n";
        bool yes = 0;
        f(i, 0, n-1) 
        {
            if(s[0][i]=='#')
                {
                    tot = 0;
                    mem(v, 0);
                    visit(0, i);
                    if(has==tot)
                        yes = 1;
                    found = 1;
                }
                if(s[1][i]=='#')
                {
                    tot = 0;
                    mem(v, 0);
                    visit(1, i);
                    if(has==tot)
                        yes = 1;
                    found = 1;
                }
                if(found==1)
                    break;
        }
        
        if(yes)
            cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}

