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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a, b, f, k;
    while(cin>>a>>b>>f>>k)
    {
        if(b<f || b<a-f)
        {
            cout << "-1\n";
            continue;
        }
        if(k==2 && (b<2*(a-f)||b<f))
        {
            cout << "-1\n";
            continue;
        }
        if(k>=3 && (b<2*(a-f) || b<2*f))
        {
            cout << "-1\n";
            continue;
        }
        int cnt = 0;
        int rem = b;
        while(k>0)
        {
            //cout << k << ": " << rem << ", " << cnt << " => ";
            if(k==1)
            {
                if(rem<a)
                {
                    cnt++;
                }
                k--;
                break;
            }
            else if(k==2)
            {
                if(rem>=2*a)
                {
                    rem-=2*a;
                }
                else if(rem>=a+a-f)
                {
                    cnt++;
                    rem = b - f;
                }
                else
                {
                    cnt++;
                    rem=b;
                    if(rem<a-f+a)
                    {
                        cnt++;
                        rem = b - f;
                    }
                    else rem = b - (a-f+a);
                }
                k-=2;
                break;
            }
            else if(k>=3)
            {
                if(rem>=2*a + f)
                {
                    rem-=2*a;
                }
                else if(rem>=a+a-f)
                {
                    cnt++;
                    rem = b - f;
                }
                else
                {
                    cnt++;
                    rem = b;
                    if(rem<2*a)
                    {
                        cnt++;
                        rem = b - f;
                    }
                    else rem = b - (a-f+a);
                }
                k-=2;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

