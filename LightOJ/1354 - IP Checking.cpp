/**********************************************************
Status:     Accepted
Problem:
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
Created on:
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
int deci(int n)
{
    int d=0, p=0;
    while(n>0)
    {
        int r=n%10;
        d=d+r*pow(2, p);
        n/=10;
        p++;
    }
    return d;
}
int main()
{
    freopen("in.txt", "r", stdin);
    int t, cas, s1, s2, s3, s4, f1, f2, f3, f4, len1, len2, i, j;
    char first[25], second[50], temp[15];
    scanf("%d", &t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%s", first);
        scanf("%s", second);
        len1=strlen(first);
        len2=strlen(second);

        for(j=0, i=0;first[i]!='.';i++)
            temp[j++]=first[i];
        temp[j]='\0';
        f1=atoi(temp);

        for(j=0, i=i+1;first[i]!='.';i++)
            temp[j++]=first[i];
        temp[j]='\0';
        f2=atoi(temp);

        for(j=0, i=i+1;first[i]!='.';i++)
            temp[j++]=first[i];
        temp[j]='\0';
        f3=atoi(temp);

        for(j=0, i=i+1;i<len1;i++)
            temp[j++]=first[i];
        temp[j]='\0';
        f4=atoi(temp);

        for(j=0, i=0;second[i]!='.';i++)
            temp[j++]=second[i];
        temp[j]='\0';
        s1=atoi(temp);

        for(j=0, i=i+1;second[i]!='.';i++)
            temp[j++]=second[i];
        temp[j]='\0';
        s2=atoi(temp);

        for(j=0, i=i+1;second[i]!='.';i++)
            temp[j++]=second[i];
        temp[j]='\0';
        s3=atoi(temp);

        for(j=0, i=i+1;i<len2;i++)
            temp[j++]=second[i];
        temp[j]='\0';
        s4=atoi(temp);

        s1=deci(s1);
        s2=deci(s2);
        s3=deci(s3);
        s4=deci(s4);

        if(f1==s1 && f2==s2 && f3==s3 && f4==s4)
            printf("Case %d: Yes\n", cas);
        else printf("Case %d: No\n", cas);
    }
    return 0;
}
/**********************************************************
About this problem:

************************************************************/
