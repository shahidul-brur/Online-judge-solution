#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int main()
{
   // freopen("A.txt", "r", stdin);

    int nA, nB, k, m, A[100002], B[100002], yes, c;
    scanf("%d %d", &nA, &nB);
    scanf("%d %d", &k, &m);
    for(int i=0;i<nA;i++)
        scanf("%d", &A[i]);
    for(int i=0;i<nB;i++)
        scanf("%d", &B[i]);
    yes=1;
    c=B[nB-m];
    for(int i=0;i<k;i++)
    {
        if(A[i]>=c)
        {
            yes=0;
            break;
        }
    }
    if(yes==1)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}