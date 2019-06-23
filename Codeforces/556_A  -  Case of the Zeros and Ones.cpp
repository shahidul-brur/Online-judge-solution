#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, zero=0, one=0, i;
    char s[200005];
    scanf("%d",&n);
    scanf("%s", s);
    for(i=0;i<n;i++)
        if(s[i]=='0')
            zero++;
        else one++;

    if(one<zero)
        printf("%d\n", n-2*one);
    else printf("%d\n", n-2*zero);
    return 0;
}