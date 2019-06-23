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
string vow = "aeiou";
bool isCons(char c)
{
    f(i, 0, 4)
        if(c==vow[i])
            return 0;
    return 1;
}
int sp[3005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin>>s)
    {
        mem(sp, 0);
        int n = s.length();
        
        vector<pair<char, pair<int, int> > > cc;
        for(int i = 0;i<n;)
        {
            //cout << i << ": ";
            if(isCons(s[i]))
            {
                int st = i;
                if(i+1<n && s[i+1]==s[i])
                {
                    while(i+1<n && s[i+1]==s[i])
                        i++;
                }
                
                cc.pb(mp(s[i], mp(st, i))); // c, s, e
                int siz = cc.size(), f = 0;
                for(int j = 0;j<siz;j++)
                    f+=cc[j].ss.ss - cc[j].ss.ff+1;
                
                if(cc.size()>=2 && f>=3)
                {
                    //cout << i << "\n";
                    if(cc[0].ss.ss - cc[0].ss.ff+1==1)
                    {
                        sp[cc[1].ss.ff] = 1;
                        cc.erase(cc.begin());
                        if(cc[0].ss.ss - cc[0].ss.ff+1==1)
                            cc.erase(cc.begin());
                        else 
                        {
                            cc[0].ss.ff+=1;
                        }
                    }
                    else
                    {
                        sp[cc[0].ss.ss] = 1;
                        cc.erase(cc.begin());
                    }
                }
                i++;
            }
            else 
            {
                i++;
                cc.clear();
            }
//            int k = cc.size();
//            f(j, 0, k-1)
//            {
//                cout << cc[j];
//            }
            //cout << "\n";
        }
        //cout << s << "\n";
        for(int i = 0;i<n;i++)
        {
            cout << s[i];
            if(sp[i] && i<n-1)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

