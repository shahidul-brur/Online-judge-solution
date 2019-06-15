//Accepted

#include <bits/stdc++.h>
#define maxi 1010
using namespace std;
typedef struct elephant
{
    int w, iq, index;
};
elephant E[maxi];
bool cmp(const elephant& a, const elephant& b)
{
    if(a.w < b.w)
        return true;
    else if(a.w>b.w)
        return false;
    else return (a.iq > b.iq);
}
int dp[maxi], s, parent[maxi];
int calLis(int i)
{
    int m = -1;
    for(int j=i+1;j<s;j++)
    {
        int way = 0;
        if(E[j].w > E[i].w && E[j].iq<E[i].iq)
        {
            if(dp[j]!=-1)
                way = dp[j];
            else way = calLis(j);
        }
        m = max(m, way);
    }
    return dp[i] = m+1;
}
int main()
{
    //freopen("10131.txt", "r", stdin);
    memset(dp, -1, sizeof(dp));
    int i, j, k, mx, iq, w;
    s=0;
    while(scanf("%d %d", &w, &iq)!=EOF)
    {
        E[s].index = s+1;
        E[s].w = w;
        E[s].iq = iq;
        s++;
    }
    sort(E, E+s, cmp);
    
    mx = -1;
    int start = 0;
    for(i=0;i<s;i++)
    {
        int cnt = calLis(i);
        if(cnt > mx)
        {
            mx = cnt;
            start = i;
        }
    }
    cout << mx << "\n" << E[start].index << "\n";
    
    for(i=start+1;i<s;i++)
    {
        if(dp[i]>0 && dp[i] == dp[start]-1)
        {
            cout << E[i].index << "\n";
            start = i;
        }
    }
    return 0;
}
