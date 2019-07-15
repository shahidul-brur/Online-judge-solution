#include<bits/stdc++.h>
using namespace std;
string s[2];
int n;
int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, ans, both;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s[0]>>s[1];
        ans = both = 0;
        for(int i=0;i<n;i++)
        {
            if(s[0][i]=='*' || s[1][i]=='*')
                ans++;
            if(s[0][i]=='*' && s[1][i]=='*')
                both++;
        }
        if(ans>0 && both==0)
            ans-=1;
        int tot = 1, up = 0, down = 0;
        for(int i=0;i<n;i++)
        {
            if(s[0][i]=='*' && s[1][i]!='*')
            {
                if(up==0)
                    up = 1;
                else 
                {
                    tot++;
                    down = 0;
                }
            }
            else if(s[1][i]=='*' && s[0][i]!='*')
            {
                if(down==0)
                    down = 1;
                else 
                {
                    tot++;
                    up = 0;
                }
            }
            else if(s[0][i]=='*' && s[1][i]=='*')
            {
                if(up==1 || down==1)
                {
                    tot++;
                }
                up = 1;
                down = 1;
            }
        }
        ans = min(ans, tot);
        cout << ans << "\n";
    }
    return 0;
}

