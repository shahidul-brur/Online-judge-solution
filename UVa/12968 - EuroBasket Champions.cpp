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

int main()
{
    fast;
    in;
    //out;
    int player[15], scores[15], value, i, j, test, selected[8], k, l, m;
    cin>>test;
    while(test--)
    {
        mem(player, 0);
        mem(selected, 0);
        for(i=4;i<=13;i++)
        {
            for(j=0;j<12;j++)
            {
                cin>>value;
                player[i]+=value;
            }
        }
        int mx = -1;
        for(i=4;i<=13;i++)
            for(j=i+1;j<=13;j++)
                for(k=j+1;k<=13;k++)
                    for(l=k+1;l<=13;l++)
                        for(m=l+1;m<=13;m++)
                            if(player[i]+player[j]+player[k]+player[l]+player[m]>mx)
                            {
                                mx = player[i]+player[j]+player[k]+player[l]+player[m];
                                selected[1]=i;
                                selected[2]=j;
                                selected[3]=k;
                                selected[4]=l;
                                selected[5]=m;
                            }
            
        
        for(j=1;j<=5;j++)
        {
            if(j>1)
                cout << " ";
            cout << selected[j];
        }
        cout << "\n";
    }
    return 0;
}