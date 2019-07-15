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
const int MX = 1000005;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        bool y = 1;
        int cur = 0; // 1 = 'H', 2 = 'T'
        f(i, 0, n-1)
        {
            
            if(s[i]=='T')
            {
                if(cur!=1)
                {
                    y = 0;
                    break;
                }
                cur = 2;
            }
            else if(s[i]=='H')
            {
                if(cur==1)
                {
                    y = 0;
                    break;
                }
                cur = 1;
            }
        }
        if(cur==1)
        {
            y = 0;
        }
        if(y)
            cout << "Valid\n";
        else
            cout << "Invalid\n";
    }
    return 0;
}

