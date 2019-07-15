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
#define debug(x)        cerr << "   ## " << #x << " = " << x << " ...\n"
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
int a[MX+5], b[MX+5];
int freq[MX+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        set<int> sett;
        mem(freq, 0);
        f(i, 0, n-1)
        {
            cin>>a[i];
            sett.insert(i);
            freq[a[i]]++;
        }
        
        f(val, 1, MX)
        {
            f(j, 1, freq[val])
            {
                auto it = sett.end();
                --it;
                while(a[*it]==val){
                    if(it==sett.begin())
                        break;
                    --it;
                }
                b[*it] = val;
                int pos = *it;
                sett.erase(it);
                if(a[pos]==b[pos])
                {
                    f(k, 0, n-1)
                    {
                        if(a[k]!=b[pos] && b[k]!=b[pos])
                        {
                            swap(b[pos], b[k]);
                            break;
                        }
                    }
                }
                    
            }
        }
        int dis = 0;
        f(i, 0, n-1)
        {
            if(a[i]!=b[i])
                dis++;
        }
        cout << dis << "\n" << b[0];
        f(i, 1, n-1)
        {
            cout << " " << b[i];
        }
        cout << "\n";
    }
    return 0;
}

