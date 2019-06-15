#include<bits/stdc++.h>
#define MIN(a, b) (a<b ? a:b)
#define MAXI(a, b) (a>b ? a:b)
using namespace std;
int toNum(char *s)
{
    int len=strlen(s);
    int d=0, i;
    for(i=1;i<len;i++)
    {
        d=d*10+s[i]-'0';
    }
    return d;
}
int main()
{
    freopen("1235.txt", "r", stdin);
    int t, n, cnt, done[10002], i, j, k, a, b, c, mini, a1, b1;
    char key1[6], key2[6];
    scanf("%d", &t);
    while(t--)
    {
        mini=1000;
        scanf("%d", &n);
        memset(done, 0, sizeof(done));
        cnt=0;
        strcpy(key1, "0000");
        for(j=0;j<n;j++)
        {
            scanf("%s", key2);
            //k=toNum(key2);
            for(i=0, c=0;i<4;i++)
            {
                a1=key1[i]-'0';
                b1=key2[i]-'0';
                a=MIN(a1, b1);
                b=MAXI(a1, b1);
                a1=(b-a);
                b1=a+10-b;
                c+=MIN(a1, b1);
            }
            printf("%d ", c);
            strcpy(key1, key2);
        }
        printf("\n");
        //printf("%d\n", cnt);
    }
    return 0;
}
