#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt=0, i, j, c1, c2;
    char s[105][105];
    cin>>n;
    for(i=0;i<n;i++)
        cin>>s[i];
    for(i=0;i<n;i++)
    {
        c1 = c2 = 0;
        for(j=0;j<n;j++)
        {
            if(s[i][j]=='C')
                c1++;
            if(s[j][i]=='C')
                c2++;
        }
        cnt+=c1*(c1-1)/2 + c2*(c2-1)/2;
    }
    cout << cnt << "\n";
    return 0;
}
