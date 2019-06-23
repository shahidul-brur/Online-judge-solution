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

int n, a[100005], c[100005], m, mm, cm, cmm;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    while(cin>>n)
    {
        m = 1000000010;
        mm = -1;
        cm = cmm = 0;
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<m)
            {
                m = a[i];
                cm = 1;
            }
            else if(a[i]==m)
                cm++;
            if(a[i]>mm)
            {
                mm = a[i];
                cmm = 1;
            }
            else if(a[i]==mm)
                cmm++;
        }
        if(m==mm)
        {
            cout << n - cm << "\n";
        }
        else cout << n - (cm + cmm) << "\n";
    }
    return 0;
}


