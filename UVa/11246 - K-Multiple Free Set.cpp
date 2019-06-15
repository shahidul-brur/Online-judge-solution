/**********************************************************
Status:
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
bool mark[100005];
int main()
{
   // freopen("in.txt", "r", stdin);
    int n, k, ans, test, j, i, cnt;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &k);
        int r = sqrt(n);
        cnt=0;
        memset(mark, 0, sizeof(mark));
        for(i=1;i<=r;i++)
        {
            if(mark[i]==0)
            {
                cnt++;
                mark[k*i] = 1;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
