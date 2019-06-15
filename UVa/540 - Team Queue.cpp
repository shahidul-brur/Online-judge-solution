/*=================================*\
                                   
      Md. Shahidul Islam           
         CSE, BRUR                 
      Rangpur, Bangladesh          
 mail: shahidul.cse.brur@gmail.com 
 FB  : fb.com/shahidul.brur        
 Blog: shahidul-brur.blogspot.com 
\*=================================*/
// AC, 22-Dec-2017
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
const int MX = 200005;
int id[10000005];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int team, cas=1;
    while(cin>>team)
    {
        if(team==0) break;
        queue<int> teams[1005], q;
        f(i, 1, team)
        {
            int members,x;
            cin>>members;
            f(j, 1, members)
            {
                cin>>x;
                id[x] = i;
            } 
        }
        string cmd;
        cout << "Scenario #" << cas << "\n";
        cas++;
        while(1)
        {
            cin>>cmd;
            if(cmd=="STOP")
                break;
            else if(cmd=="ENQUEUE")
            {
                int x;
                cin>>x;
                if(teams[id[x]].empty())
                    q.push(id[x]);
                teams[id[x]].push(x);
            }
            else 
            {
                int x = q.front();
                cout << teams[x].front() << "\n";
                teams[x].pop();
                if(teams[x].empty())
                    q.pop();
            }
        }
        cout << "\n";
    }
    return 0;
}

