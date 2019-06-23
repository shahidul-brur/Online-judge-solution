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
#define rep0(i, k)      for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define repab(i, a, b)  for(int i=a;i<=b;i++)
#define repba(i, b, a)  for(int i=b;i>=a;i--)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define inf             1e9
int col[100005], used[100005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin>>n;
    if(n==1)
    {
        cout << "1\n1\n";
        return 0;
    }
    else if(n==2)
    {
        cout << "1\n1 1\n";
        return 0;
    }
    col[2] = 1;
    for(int i = 4;i<=n+1;i+=2)
        used[i] = 1, col[i] = 2;
    for(int i = 3;i<=n+1;i+=2)
    {
        if(used[i]==0)
        {
            col[i] = 1;
            for(int j = i+i;j<=n+1;j+=i)
            {
                used[j] = 1;
            }
        }
        else col[i] = 2;
    }
    cout << "2\n";
    for(int i = 2;i<=n+1;i++)
        cout << col[i] << " ";
    cout << "\n";
    return 0;
}
