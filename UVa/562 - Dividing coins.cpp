#include<bits/stdc++.h>
using namespace std;
int dp[102][50005];
int coin[102], n, run, total;

int findMini(int pos, int sum)
{
    if(pos>n)
    {
        int other = total - sum;
        return abs(sum-other);
    }
    if(dp[pos][sum]!=-1)
        return dp[pos][sum];
    int m1 = findMini(pos+1, sum+coin[pos]);
    int m2 = findMini(pos+1, sum);
    
    dp[pos][sum] = min(m1, m2);
    return dp[pos][sum];
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(dp, -1, sizeof dp);
        total = 0;
        for(int i=1;i<=n;i++)
            cin>>coin[i], total+=coin[i];
        cout << findMini(1, 0) << "\n";
    }
    return 0;
}
