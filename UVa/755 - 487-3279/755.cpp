//Accepted

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("755.txt", "r", stdin);
    int t, c, n, i, j, len, phone[100009], d, tmp, cnt, dup;
    char num[100];
    scanf("%d",&t);
    for(c=1;c<=t;c++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",num);
            len=strlen(num);
            d=0;
            for(j=0;j<len;j++)
            {
                if(num[j]=='A' || num[j]=='B' || num[j]=='C')
                    d=d*10+2;
                else if(num[j]=='D' || num[j]=='E' || num[j]=='F')
                    d=d*10+3;
                else if(num[j]=='G' || num[j]=='H' || num[j]=='I')
                    d=d*10+4;
                else if(num[j]=='J' || num[j]=='K' || num[j]=='L')
                    d=d*10+5;
                else if(num[j]=='M' || num[j]=='N' || num[j]=='O')
                    d=d*10+6;
                else if(num[j]=='P' || num[j]=='R' || num[j]=='S')
                    d=d*10+7;
                else if(num[j]=='T' || num[j]=='U' || num[j]=='V')
                    d=d*10+8;
                else if(num[j]=='W' || num[j]=='X' || num[j]=='Y')
                    d=d*10+9;
                else if(num[j]>='0' && num[j]<='9')
                    d=d*10+num[j]-'0';

            }
            phone[i]=d;
        }
        sort(phone, phone+n);
        dup=0;
        if(c>1)
            printf("\n");
        for(i=0;i<n;i++)
        {
            cnt=1;
            for(j=i+1;phone[j]==phone[i];j++)
                cnt++;
            if(cnt>1)
            {
                printf("%d%d%d-%d%d%d%d %d\n",phone[i]/1000000,(phone[i]/100000)%10,(phone[i]/10000)%10,(phone[i]/1000)%10,(phone[i]/100)%10,(phone[i]/10)%10,phone[i]%10,cnt);
                dup++;
            }
            i+=cnt-1;
        }
        if(dup==0)
            printf("No duplicates.\n");
    }
    return 0;
}
