/************************************************************
*  Problem:  uva 11690                                      *
* Link:      http://uva.onlinejudge.org/external/116/11690.html *
* Verdict:   Accepted                                       *
* Date:      2015-09-19                                     *
*                                                           *
* Coder:     Md. Shahidul Islam                             *
* Dept. :    Computer Science and Engineering               *
* Institute: Begum Rokeya University, Rangpur, Bangladesh   *
*  							                                *
*************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define mem(a, b) memset(a, (b), sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define in freopen("in.txt", "r", stdin);
#define out freopen("out.txt", "w", stdout);
#define clr(arr, key) memset(arr, key, sizeof arr)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define inf (1 << 28)
#define LL long long
#define PI acos(-1)
#define gcd(a, b) __gcd(a, b)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define lcm(a, b) ((a)*((b)/gcd(a,b)))
#define all(v) v.begin(), v.end()
#define no_of_ones __builtin_popcount // __builtin_popcountll for LL
#define SZ(v) (int)(v.size())
#define eps 1e-7
#define ppb pop_back
#define all(x) x.begin(),x.end()
#define AIN(A, B, C) assert(IN(A, B, C))
ll bigmod(ll sonkha,ll ghat,ll vag_const){ll vag_shesh=1;while(ghat>0){if(ghat%2==1){vag_shesh=(vag_shesh*sonkha)%vag_const;}ghat/=2;sonkha=(sonkha*sonkha)%vag_const;}return vag_shesh;}
ll inverse_mod(ll bivajok, ll vag_const){return bigmod(bivajok,vag_const-2, vag_const);}

typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpi;

int oweSum[10002], base[10002];
int findBaseFriend(int f)
{
    if(base[f]==f) return f;
    return base[f]=findBaseFriend(base[f]);
}
void makeFriend(int a, int b)
{
    int b1, b2;
    b1=findBaseFriend(a);
    b2=findBaseFriend(b);
    if(b1!=b2)
    {
        base[b1]=b2;
        oweSum[b1]+=oweSum[b2];
        oweSum[b2]=oweSum[b1];
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int N, n, m, i, j, a, b, yes;
    cin>>N;
    while(N--)
    {
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            base[i]=i;
            cin>>oweSum[i];
        }
        for(j=0;j<m;j++)
        {
            cin>>a>>b;
            makeFriend(a, b);
        }
        for(i=0;i<n;i++)
            if(base[i]!=i)
                base[i]=findBaseFriend(i);
        yes=1;
        for(i=0;i<n;i++)
        {
            if(oweSum[base[i]]!=0)
            {
                yes=0;
                break;
            }
        }
        if(yes==1)
            cout<<"POSSIBLE"<< "\n";
        else cout<<"IMPOSSIBLE"<< "\n";
    }
    return 0;
}