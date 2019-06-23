#include <bits/stdc++.h>
#define MIN(a,b) (a<b? a:b)
int main()
{
    int n, mov, i, a, b, c, d;
    char f[1003], t[1003];
    scanf("%d", &n);
    scanf("%s %s", f, t);
    mov=0;
    for(i=0;i<n;i++)
    {
        a=f[i]-'0';
        b=t[i]-'0';
        if(a<b)
        {
            c=a;
            d=b;
        }
        else
        {
            c=b;
            d=a;
        }
        a=d-c;
        b=c+10-d;
        mov+=MIN(a, b);
    }
    printf("%d\n", mov);
    return 0;
}