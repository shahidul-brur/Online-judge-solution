#include<bits/stdc++.h>
using namespace std;
#define D(x)        cout<<#x " = "<<(x)<<endl
#define un(x)       x.erase(unique(x.begin(),x.end()), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pb          push_back
#define mp          make_pair
#define xx          first
#define yy          second
#define hp          (LL) 999983
#define MAX         1000000
#define eps         1e-9
#define pi          acos(-1.00)
typedef long long int LL;
typedef pair<int,int> pii;

int rs_needed[MAX+5];
int arr[MAX+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    int i, j, k, n, idx = 0, rs, lst_pos, cminus = 0, cplus = 0;
    LL dv = 0, mn;

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        sf(arr[i]);
        dv += abs(arr[i] - i);
        if(arr[i] > i){
            rs_needed[arr[i] - i]++;
            cminus++;
        }
        else{
            rs_needed[ n - i + arr[i]]++;
            cplus++;
        }
    }
    
    mn = dv;
    lst_pos = n;
    
    for(rs = 0; rs < n; rs++)
    {
        if(dv < mn) mn = dv, idx = rs;
        cminus-=rs_needed[rs];
        cplus+=rs_needed[rs];
        
        dv -= n - arr[lst_pos];
        dv += arr[lst_pos];
        lst_pos--;

        cplus--;
        cminus++;

        dv = dv + cplus - cminus;
    }

    printf("%lld %d\n", mn, idx);
    return 0;
}
