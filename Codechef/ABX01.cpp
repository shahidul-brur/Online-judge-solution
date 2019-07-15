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
ll po(ll b, ll p)
{
    ll ans = 1;
    f(i, 1, p)
        ans*=b;
    return ans;
}
ll sumInt(int n)
{
    while(n>9)
    {
        int s = 0;
        while(n>0)
        {
            s+=n%10;
            n/=10;
        }
        n = s;
    }
    return n;
}
ll sum(string n)
{
    int ans = 0;
    int l = n.length();
    f(i, 0, l-1)
    {
        ans+=n[i] - '0';
    }
    return sumInt(ans);
}
int Mod(string n, int m)
{
    int rem = 0;
    for(int i = 0;i<n.length();i++)
    {
        rem = rem*10 + n[i] - '0';
        rem%=m;
    }
    return rem;
}
int seq2[] = {1, 2, 4, 8, 7, 5};
int seq4[] = {1, 4, 7};
int seq5[] = {1, 5, 7, 8, 4, 2};
int seq7[] = {1, 7, 4};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("seqI.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    f(cas, 1, t)
    {
        string a, b;
        cin>>a>>b;
        int A = sum(a);
        if(A==1)
            cout << "1\n";
        else if(A==0)
            cout << "0\n";
        else if(b=="1")
            cout << A << "\n";
        else if(b=="0")
            cout << "1\n";
        else 
        {
            if(A==3 || A==6 || A==9)
            {
                if(b=="1")
                    cout << A << "\n";
                else cout << "9\n";
            }
            else if(A == 8)
            {
                if((b[b.length()-1] - '0')%2==1)
                    cout << "8\n";
                else cout << "1\n";
            }
            else if(A==2)
            {
                int m = Mod(b, 6);
                cout << seq2[m] << "\n";
            }
            else if(A==4)
            {
                int m = Mod(b, 3);
                cout << seq4[m] << "\n";
            }
            else if(A==5)
            {
                int m = Mod(b, 6);
                cout << seq5[m] << "\n";
            }
            else if(A==7)
            {
                int m = Mod(b, 3);
                cout << seq7[m] << "\n";
            }
        }
    }
    return 0;
}

