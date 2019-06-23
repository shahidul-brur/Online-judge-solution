/*=================================*\
|                                   |
|      Md. Shahidul Islam           |
|         CSE, BRUR                 |
|      Rangpur, Bangladesh          |
| mail: shahidul.cse.brur@gmail.com |
| FB  : fb.com/shahidul.brur        |
|                                   |
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define F(i, a, b) for(int i=a;i<=b;i++)
#define Fr(i, b, a) for(int i=b;i>=a;i--)
#define pi acos(-1)
#define eps 1e-6
#define mem(a, b) memset(a, b, sizeof(a))
#define ll long long
#define ull unsinged long long
#define mod 1000000007
#define N 100000
map<pair<int, int>, pair<int, int> > ma;
int k, ans[3], a[100005][4], mx;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int i, j, n;
    //string s, t;
    
    while(cin>>n)
    {
        i=1;
        for(j=0;j<=2;j++)
            cin>>a[i][j];
        sort(a[i], a[i]+3);
        if(a[i][0]>mx)
        {
            mx = a[i][0];
            k = 1;
            ans[0] = i;
        }
        ma[make_pair(a[i][0], a[i][1])] = make_pair(a[i][2], i);
        if(a[i][1]!=a[i][2])
            ma[mp(a[i][0], a[i][2])] = mp(a[i][1], i);
        if(a[i][1]!=a[i][0])
            ma[mp(a[i][1], a[i][2])] = mp(a[i][0], i);
        F(i, 2, n)
        {
            F(j, 0, 2)
                cin>>a[i][j];
            sort(a[i], a[i]+3);
            if(a[i][0]>mx)
            {
                mx = a[i][0];
                k = 1;
                ans[0] = i;
            }
            int f = ma[make_pair(a[i][0], a[i][1])].first;
            int s = ma[make_pair(a[i][0], a[i][1])].second;
            if(f==0)
                ma[make_pair(a[i][0], a[i][1])] = make_pair(a[i][2], i);
            else
            {
                if(min(a[i][0], min(a[i][1], a[i][2]+f))>mx)
                {
                    mx = min(a[i][0], min(a[i][1], a[i][2]+f));
                    k = 2;
                    ans[0] = i;
                    ans[1] = s;
                }
                if(a[i][2]>f)
                    ma[make_pair(a[i][0], a[i][1])] = make_pair(a[i][2], i);
            }
            
            f = ma[make_pair(a[i][1], a[i][2])].first;
            s = ma[make_pair(a[i][1], a[i][2])].second;
            if(f==0)
                ma[make_pair(a[i][1], a[i][2])] = make_pair(a[i][0], i);
            else
            {
                if(min(a[i][1], min(a[i][2], a[i][0]+f))>mx)
                {
                    mx = min(a[i][1], min(a[i][2], a[i][0]+f));
                    k = 2;
                    ans[0] = i;
                    ans[1] = s;
                }
                if(a[i][0]>f)
                    ma[make_pair(a[i][1], a[i][2])] = make_pair(a[i][0], i);
            }
            
            f = ma[make_pair(a[i][0], a[i][2])].first;
            s = ma[make_pair(a[i][0], a[i][2])].second;
            if(f==0)
                ma[make_pair(a[i][0], a[i][2])] = make_pair(a[i][1], i);
            else
            {
                if(min(a[i][0], min(a[i][2], a[i][1]+f))>mx)
                {
                    mx = min(a[i][0], min(a[i][2], a[i][1]+f));
                    k = 2;
                    ans[0] = i;
                    ans[1] = s;
                }
                if(a[i][1]>f)
                    ma[make_pair(a[i][0], a[i][2])] = make_pair(a[i][1], i);
            }
        }
        cout << k << "\n";
        F(i, 0, k-1)
            cout << ans[i] << " ";
    }
    return 0;
}

