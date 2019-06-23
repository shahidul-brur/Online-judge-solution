/*=================================*\

	  Md. Shahidul Islam
		 CSE, BRUR
	  Rangpur, Bangladesh
 mail: shahidul.cse.brur@gmail.com
 FB  : fb.com/shahidul.brur
 Blog: shahidul-brur.blogspot.com(in Bengali),
	   shahidul-brur-en.blogspot.com(in English)
\*=================================*/
#include<bits/stdc++.h>
using namespace std;

#define pb			  push_back
#define debug(x)	  cerr << "   ## " << #x << " = " << x << " ...\n"
#define mp			  make_pair
#define ff			  first
#define ss			  second
#define sz			  size()
#define all(a)		  a.begin(), a.end()
#define f(i, a, b)	  for(int i=(a);i<=(b);i++)
#define F(i, b, a)	  for(int i=(b);i>=(a);i--)
#define PI			  acos(-1.0)
#define EPS			  1e-6
#define mem(a, b)	  memset(a, b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> v;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<float> vf;
typedef pair<int, int> ii;
typedef vector<ii> vii;

//			  0123456789
const int MOD = 1000000007;
const int MX  = 100002;
const int INF = 2147483647;
int dx[] = {0, -1, 1};
int dy[] = {1, 1, 1};
int n, k;
struct state {
    int r, c;
    set<ii> buses[3];
};
bool visited[3][4][103];
bool ans;
int c;
void check(int mov, state cur) // mov=1:player, mov = 2:bus
{
	int cur_r = cur.r;
	int cur_c = cur.c;
	if(visited[mov][cur_r][cur_c])
		return;
	visited[mov][cur_r][cur_c] = 1;
    if(mov==1 && cur.buses[cur_r].empty()) {
        ans = 1;
        return;
    }
    
    if((*cur.buses[cur_r].begin()).ff==cur_c+1)
	{
		return;
	}
	if(mov==1){
        for(int i = 0; i<3; i++) {
            int nr = cur_r + dx[i];
            int nc = cur_c + dy[i];
            if(nr<0 || nr==3 || nc<0 || nc==n)
			{
				continue;
			}
            bool ok = 1;
            for(ii b:cur.buses[nr]) {
                if(nc>=b.first && nc<=b.second){
					ok = 0;
                    break;
                }
            }
            if(ok) {
				state nxt = cur;
                nxt.r = nr;
                nxt.c = nc;
                check(2, nxt);
            }
        }
    } else {
    	if(cur.buses[0].empty() && cur.buses[1].empty() && cur.buses[2].empty())
		{
			return;
		}
        state nxt;
        nxt.r = cur_r;
        nxt.c = cur_c;
        bool ok = 1;
        f(i, 0, 2) {
            for(ii b:cur.buses[i]) {
                int beg = b.ff, en = b.ss;
                if(en-2>cur_c)
                    nxt.buses[i].insert(mp(beg-2, en-2));
                if(i==cur_r && b.ff-2<=cur_c) {
                    ok = 0;
                    break;
                }
            }
            if(!ok)
                break;
        }
        if(ok)
		{
			check(1, nxt);
		}
    }
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    scanf("%d", &t);
    int cas=1;
    while(cas<=t) {
		mem(visited, 0);
		ans = 0;
        scanf("%d %d", &n, &k);
        char s[3][105];
        f(i, 0, 2)
			scanf("%s", s[i]);
        state cur;
        f(i, 0, 2) {
            f(j, 0, n-1) {
                if(s[i][j]=='s') {
                    cur.r = i;
                    cur.c = j;
                } else if(isupper(s[i][j])) {
                    f(k, j, n-1) {
                        if(k+1==n || !isupper(s[i][k+1])) {
                            cur.buses[i].insert(mp(j, k));
                            j = k;
                            break;
                        }
                    }

                }
            }
        }
        check(1, cur);
        if(ans)
            puts("YES\n");
        else puts("NO\n");
        cas++;
    }
    return 0;
}

