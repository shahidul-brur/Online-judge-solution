#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, i, j , f[28], cnt=0;
    char s[110];
    memset(f, 0, sizeof(f));
    scanf("%d", &n);
    scanf("%s", s);
    for(i=0;i<n;i++)
    {
        if(s[i]>='A' && s[i]<='Z' )
            f[s[i]-'A']++;
        else f[s[i]-'a']++;
    }
    for(i=0;i<26;i++)
        if(f[i]>0)
            cnt++;
    if(cnt==26)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}