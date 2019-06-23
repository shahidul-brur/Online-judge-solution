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

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vii;

#define pb              push_back
#define f(i, a, b)      for(int i=(a);i<=(b);i++)

const int MX = 2000005;
bool ok[MX];
char ans[MX];
char s[MX];
int mx;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    scanf("%d", &n);
    
    set<int> st;
    set<int>::iterator it;
    f(i, 0, MX-5)
        st.insert(i);
    mx = 0;
    f(i, 1, n)
    {
        scanf("%s", s);
        
        int len = strlen(s);
        
        int k;
        scanf("%d", &k);
        f(i, 1, k)
        {
            int l;
            scanf("%d", &l);;
            --l;
            int r = l+len-1;
            mx = max(mx, r);
            for(it = st.lower_bound(l);it!=st.end();)
            {
                int p = *it;
                if(p>=l && p<=r)
                {
                    ans[p] = s[p - l];
                    ok[p] = 1;
                    st.erase(it++);
                }
                else break;
            }
        }
    }
    f(i, 0, mx)
    {
        if(ok[i]==1)
            printf("%c", ans[i]);
        else printf("a");
    }
    printf("\n");
    return 0;
}


