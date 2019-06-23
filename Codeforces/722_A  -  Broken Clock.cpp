#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int> > vii;

#define pb push_back
#define mp make_pair
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
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t, n, i, j;
    int f, h, m;
    scanf("%d", &f);
    scanf("%d:%d", &h, &m);
    //cout << h <<" " << m << "\n";
    if(f==12)
    {
        if(m>59)
        {
            if(m%10==0)
                m=0;
            else m = m%10;
        }
        if(h>12)
        {
            if(h%10==0)
                h=10;
            else h%=10;
        }
        else if(h==0)
            h=1;
    }
    else
    {
        if(m>59)
        {
            if(m%10==0)
                m=0;
            else m = m%10;
        }
        if(h>23)
        {
            h%=10;
        }
    }
    printf("%02d:%02d\n", h, m);
    return 0;
}