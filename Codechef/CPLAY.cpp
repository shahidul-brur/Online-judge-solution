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

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    while(cin>>s){
        int A = 0, B = 0;
        int win = 0;
        int ta = 0, tb = 0, turn = 0;
        for(int i = 0;i<20;i++){
            if(i&1)
                tb++;
            else ta++;
            if(s[i]=='1'){
                if(i&1)
                    B++;
                else A++;
            }
            if(i<10 && A>B && A > B + 5 - tb){
                win = 1;
                turn = i+1;
                break;
            }
            if(i<10 && B>A && B > A + 5 - ta){
                win = 2;
                turn = i+1;
                break;
            }
            if(i>=10 && i&1 && A>B){
                win = 1;
                turn = i+1;
                break;
            }
            if(i>=10 && i&1 && B>A){
                win = 2;
                turn = i+1;
                break;
            }
        }
        if(win==0)
            cout << "TIE\n";
        else if(win==1)
            cout << "TEAM-A " << turn << "\n";
        else if(win==2)
            cout << "TEAM-B " << turn << "\n";
    }
    return 0;
}

