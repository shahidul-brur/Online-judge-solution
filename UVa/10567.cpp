#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int index(char ch)
{
    if(ch>='A'&&ch<='Z')
        return (ch-'A');
    else
        return (ch-'a'+26);
}
int lowerBound(char *s, int L, int R, char ch)
{
    int mid=-1, index;
    while(L<=R)
    {
        mid=(L+R)/2;
        if(s[mid]==ch)
        {
            index=mid;
            R=mid-1;
        }
        else if(ch<s[mid])
            R=mid-1;
        else
            L=mid+1;
    }
    return index;
}
int main()
{
    freopen("10567.txt", "r", stdin);
    char str[1000005], sub[105];
    int L1, L2, q, i, f1[55], f2[55],match, a, b;
    scanf("%s", str);
    L1=strlen(str);
    scanf("%d", &q);
    memset(f1, 0, sizeof(f1));

    for(i=0;i<L1;i++)
    {
        f1[index(str[i])]++;
    }
    //for(i=0;i<52;i++)
        //printf("%d => %d\n", i, f1[i]);
    while(q-->0)
    {
        scanf("%s", sub);
        L2=strlen(sub);
        memset(f2, 0, sizeof(f2));
        for(i=0;i<L2;i++)
        {
            f2[index(sub[i])]++;
        }
        match=1;
        //for(i=0;i<52;i++)
            //printf("%d => %d\n", i, f2[i]);
        for(i=0;i<52;i++)
        {
            if(f2[i]>f1[i])
            {
                match=0;
                break;
            }
        }
        if(match==0)
            printf("Not matched\n");
        else
        {
            printf("Matched %d ", lowerBound(str, 0, L1-1, sub[0]));

            b=lowerBound(str, 0, L1-1, sub[L2-1]);
            a=f2[index(sub[L2-1])];
            printf("**%d %d** ", b, a);
            printf("%d\n",(a+b));
        }
    }
    return 0;
}
