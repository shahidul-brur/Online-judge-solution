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
const int MX = 100005;
int a[MX], jump[MX], nextp[MX];
int block_size;
int n, m;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin>>n>>m;
    f(i, 0, n-1)
    {
        cin>>a[i];
    }
    block_size = sqrt(n);
    nextp[n] = n;
    jump[n] = 0;
    F(i, n-1, 0)
    {
        int nxt = min(i + a[i], n);
        
        if(nxt/block_size == i/block_size)
        {
            jump[i] = jump[nxt]+1;
            nextp[i] = nextp[nxt];
        }
        else
        {
            jump[i] = 1;
            nextp[i] = nxt;
        }
    }
    
    while(m--)
    {
        int typ;
        cin>>typ;
        if(typ==0)
        {
            int pos, val;
            cin>>pos>>val;
            pos--;
            a[pos] = val;
            F(i, pos, 0)
            {
                
                if(i/block_size == pos/block_size)
                {
                    int nxt = min(i + a[i], n);
        
                    if(nxt/block_size == i/block_size)
                    {
                        jump[i] = jump[nxt]+1;
                        nextp[i] = nextp[nxt];
                    }
                    else
                    {
                        jump[i] = 1;
                        nextp[i] = nxt;
                    }
                    
                }
                else break;
            }
        }
        else
        {
            int pos;
            cin>>pos;
            pos--;
            int last = pos, mov = 0;
            while(nextp[pos]!=n)
                mov+=jump[pos], pos = nextp[pos];
                
            while(pos+a[pos]<n)
                pos+=a[pos], mov++;
            cout << pos+1 << " " << mov + 1 << "\n";
        }
    }
    return 0;
}

