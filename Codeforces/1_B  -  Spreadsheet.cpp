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
#define F(i, a, b)      for(int i=a;i<=b;i++)
#define rep(i, k)       for(int i=0;i<k;i++)
#define rep1(i, k)      for(int i=1;i<=k;i++)
#define FORR(i, b, a)   for(int i=b;i>=a;i--)
#define FOR(i, a, b)    for(int i=a;i<=b;i++)
#define pi              acos(-1.0)
#define eps             1e-6
#define mem(a, b)       memset(a, b, sizeof(a))
#define mod             1000000007
#define N               10005
#define inf             1e9

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r, c, n, typ, i, t;
    cin>>t;
    while(t--)
    {
        char R[100005], C[100005];
        string s;
        cin>>s;
        n = s.length();
        typ = 2;
        if(s[0]=='R' && isdigit(s[1]))
        {
            FORR(i, n-1, 0)
            {
                if(s[i]=='C')
                {
                    typ = 1;
                    break;
                }
            }
        }
        
        if(typ==1)
        {
            r = c = 0;
            for(i = 1;s[i]!='C';i++)
                r = r*10 + (s[i] - '0');
            for(++i;i<n;i++)
                c = c*10 + (s[i] - '0');
            
            int siz = 0;    
            while(c>=0)
            {
                int rem = c%26;
                if(rem==0)
                {
                    C[siz++] = 'Z';
                    c=c/26 - 1;
                }
                else 
                {
                    C[siz++]=(char)(rem + 'A' - 1);
                    c/=26;
                }
                if(c==0)
                    break;
            }
            C[siz] = '\0';
            for(int i = siz-1;i>=0;i--)
                cout << C[i];
            cout<< r << "\n";
        }
        else
        {
            r = c = 0;
            for(i = 0;!isdigit(s[i]);i++)
            {
                c = c*26 + (s[i] - 'A' + 1);
            }
            
            for(;i<n;i++)
                r = r*10 + (s[i] - '0');
            cout << "R" << r << "C" << c << "\n";
        }
    }
    return 0;
}

