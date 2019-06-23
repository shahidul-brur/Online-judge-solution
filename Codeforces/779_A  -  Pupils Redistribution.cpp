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
int a[10], b[10], A[105], B[105];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        mem(a, 0);
        mem(b, 0);
        rep0(i, n) cin>>A[i], a[A[i]]++;
        rep0(i, n) cin>>B[i], b[B[i]]++;
        
        int cnt1=0, cnt2=0;
        bool yes = 1;
        rep1(i, 5)
        {
            if((a[i]+b[i])%2==1)
            {
                yes = 0;
                break;
            }
            int need = (a[i]+b[i])/2;
            if(a[i]<need)
                cnt1+=(need-a[i]);
            else cnt2+=(need-b[i]);
        }
        if(yes==0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << (cnt1+cnt2)/2 << "\n";
        }
    }
    return 0;
}

