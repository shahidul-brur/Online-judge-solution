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
string a, b;
int n, m, del[200005];
bool isSubSequence(int pos) // b in a?
{
    int j = 0;
    bool deleted[200005];
    mem(deleted, 0);
    repab(i, 0, pos)
        deleted[del[i]] = 1;
    for(int i = 0;i<n && j<m;i++)
        if(deleted[i]==0 && b[j]==a[i])
            j++;
    return (j==m);
}
int bs(int low, int high)
{
    int mx = 0;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(isSubSequence(mid))
        {
            mx = max(mx, mid+1);
            low = mid+1;
        }
        else high = mid - 1;
    }
    return mx;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while(cin>>a>>b)
    {
        n = a.length();
        m = b.length();
        rep0(i, n)  cin>>del[i], del[i]--;
        int ans = bs(0, n-1);
        cout << ans << "\n";
    }
    return 0;
}