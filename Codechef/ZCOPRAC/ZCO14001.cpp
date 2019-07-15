/************************************************************
* Problem:   
* Link:                                                     
* Verdict:   
* Date:                                                     
* 
* Coder:     Md. Shahidul Islam
* Dept. :    Computer Science and Engineering
* Institute: Begum Rokeya University, Rangpur, Bangladesh
*
*************************************************************/

#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define rep(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin)
#define out freopen("out.txt", "w", stdout)
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define ll long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
#define INF 1000000000
int dr[]={0, 0, 1, -1, 1, 1, -1, -1};
int dc[]={1, -1, 0, 0, 1, -1, 1, -1};

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;
int h, box[100002], crane, stk, status;
void command(int cmd)
{
    if(cmd==1)
    {
        if(crane>0)
            crane--;
    }
    else if(cmd==2)
    {
        if(crane<stk-1)
            crane++;
    }
    else if(cmd==3)
    {
        if(status == 0 && box[crane]>0)
        {
            status = 1;
            box[crane]--;
        }
    }
    else if(cmd==4)
    {
        if(status == 1 && box[crane]<h)
        {
            status = 0;
            box[crane]++;
        }
    }
}
int main()
{
    //fast;
    //in;
    //out;
    int cmd, i;
    while(cin>>stk>>h)
    {
        for(i=0;i<stk;i++)
            cin>>box[i];
            
        crane = status = 0;
        cmd = -1;
        while(cmd!=0)
        {
            cin>>cmd;
            if(cmd==0)
                break;
            command(cmd);
        }
        cout << box[0];
        for(i=1;i<stk;i++)
            cout << " " << box[i];
        cout << "\n";
    }
    return 0;
}