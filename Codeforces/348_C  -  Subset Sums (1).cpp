#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\emotionless\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\emotionless\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 100009
#define MM 320



using namespace std;
///******* Template ********///


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}


///***** Template ends here *****///
///********************* Code starts here ****************************
LL val[MAX];
LL sum[MAX];
int *num[MAX];
int SZ[MAX];
int q[MM + 10];

LL cv[MAX];
int v[MM + 5][MAX];

LL tmp[MM + 5];
LL lazy[MAX];

int main()
{
    int i, j, k;
    int m;
    int t, n, qq;
    cin>>n>>m>>qq;
    for(i = 1; i <= n; i++)
        cin>>val[i];
    int tot = 0;
    for(i = 1; i <= m; i++)
    {
        cin>>SZ[i];
        num[i] = new int[ SZ[i] + 10 ];
        for(j = 1; j <= SZ[i]; j++)
        {
            cin>>num[i][j];
            sum[i] += val[ num[i][j] ];
        }
        if(SZ[i] > MM)
            q[++tot] = i;
    }
    int cnt = 0;
    for(i = 1; i <= tot; i++)
    {
        cnt++;
        LL x = q[i];
        for(j = 1; j <= SZ[ x ]; j++)
            cv[ num[x][j] ] = cnt;
        for(j = 1; j <= m; j++)
        {
            for(k = 1; k <= SZ[j]; k++)
                if(cv[ num[j][k] ] == cnt )
                    v[i][j]++;
        }
    }
    memset(cv, 0, sizeof cv);

    char ch;
    int x;
    LL y;
    while(qq--)
    {
        cin>>ch;
        if(ch == '+')
        {
            cin>>x>>y;
            if(SZ[x] <= MM)
            {
                for(i = 1; i <= SZ[x]; i++)
                {
                    cv[ num[x][i] ] += y;
                }
                for(i = 1; i <= tot; i++)
                    sum [ q[i] ] += (LL)v[i][x] * y;
            }
            else
            {
                tmp[x] += y;
            }
        }
        else
        {
            cin>>x;
            LL res = sum[x];
            if(SZ[x] <= MM)
            {
                for(i = 1; i <= SZ[x]; i++)
                    res += cv[ num[x][i] ];
                for(i = 1; i <= tot; i++)
                    res += (LL)v[i][x] * (LL)tmp[ q[i] ];
                cout<<res<<endl;
            }
            else
            {
                for(i = 1; i <= tot; i++)
                {
                    res += (LL)v[i][x] * (LL)tmp[ q[i] ];
                }
                cout<<res<<endl;
            }
        }
    }
    return 0;
}
