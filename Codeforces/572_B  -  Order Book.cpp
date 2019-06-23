#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int priceB[100002], priceS[100002];
int main()
{
    //freopen("b.txt", "r", stdin);
    int B[1003], S[1003], sett, n, i, j, b=0, s=0, p, q;
    memset(priceB, 0, sizeof(priceB));
    memset(priceS, 0, sizeof(priceS));
    char dir[4];
    scanf("%d %d", &n, &sett);
    for(i=0;i<n;i++)
    {
        scanf("%s ", &dir);
        scanf("%d %d", &p, &q);
        if(dir[0]=='B')
        {
            if(priceB[p]==0)
                B[b++]=p;
            priceB[p]+=q;
        }
        else
        {
            if(priceS[p]==0)
                S[s++]=p;
            priceS[p]+=q;
        }
    }
    sort(B, B+b);
    sort(S, S+s);
    if(s>=sett)
        i=sett-1;
    else i=s-1;
    for(j=1;j<=sett && i>=0;i--, j++)
    {
        printf("S %d %d\n", S[i], priceS[S[i]]);
    }
    i=b-1;
    for(j=1;j<=sett && i>=0;i--, j++)
    {
        printf("B %d %d\n", B[i], priceB[B[i]]);
    }
    return 0;
}