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
bool isComp(int n)
{
    if(n<4)
        return 0;
    f(i, 2, 100)
    {
        if(i<n && n%i==0)
            return 1;
    }
    return 0;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int ans = 0;
        if(n<4)
            ans = -1;
        else if(n%4==0)
            ans = n/4;
        else 
        {
            if(n>=6 && (n-6)%4==0)
                ans = 1 + (n-6)/4;
            else if(n>=9 && (n-9)%4==0)
                ans = 1 + (n-9)/4;
            else if(n>=15 && (n-15)%4==0)
                ans = 2 + (n-15)/4;
            else 
            {
                if(isComp(n))
                    ans = 1;
                else ans = -1;
            }
        }
        //cout << n << " ";
        cout << ans << "\n";
    }
    return 0;
}
