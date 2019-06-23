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
//             0123456789
const int MX = 100000;
int l[105], r[105];
int par[105];
int findPar(int x)
{
    if(par[x]==x)
        return x;
    return par[x] = findPar(par[x]);
}
void makeUnion(int x, int y)
{
    int px = findPar(x);
    int py = findPar(y);
    if(px==py)
        return;
    if(px<py)
        par[py] = px;
    else par[px] = py;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    
    for(int i =1;i<=n;i++)
        par[i] = i;
        
    for(int i =1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        if(l[i]!=0)
            makeUnion(i, l[i]);
        if(r[i]!=0)
            makeUnion(i, r[i]);
    }
    
    for(int i =1;i<=n;i++)
    {
        int x = l[i];
        while(x!=0)
        {
            makeUnion(x, i);
            x = l[x];
        }
        x = r[i];
        while(x!=0)
        {
            makeUnion(x, i);
            x = r[x];
        }
    }
    
    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
            findPar(j);
        
        if(l[i]==0)
        {
            for(int j =1;j<=n;j++)
            {
                if(par[i]!=par[j] && r[j]==0)
                {
                    //cout << "1 par "<< i <<": " << par[i] << "\n";
                    //cout << "2 par "<< j <<": " << par[i] << "\n";
                    l[i] = j;
                    r[j] = i;
                    makeUnion(j, i);
                    break;
                }
            }
        }
        
        for(int j =1;j<=n;j++)
            findPar(j);    
        if(r[i]==0)
        {
            for(int j =1;j<=n;j++)
            {
                if(par[i]!=par[j] && l[j]==0)
                {
                    //cout << "1 par "<< i <<": " << par[i] << "\n";
                    //cout << "2 par "<< j <<": " << par[i] << "\n";
                    l[j] = i;
                    r[i] = j;
                    makeUnion(j, i);
                    break;
                }
            }
        }
    }
    
    for(int i =1;i<=n;i++)
    {
        //cout << i << " : ";
        cout << l[i] << " " << r[i] << "\n";
    }
    return 0;
}

