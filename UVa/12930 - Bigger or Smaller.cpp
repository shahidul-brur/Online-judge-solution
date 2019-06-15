/**********************************************************
Status:     Accepted
Problem:    UVa 12930
Author:     Md. Shahidul Islam,
            Department of Computer Sciemce and Engineering,
            Begum Rokeya University, Rangpur, Bangladesh
***********************************************************/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define vi vector<int>
#define ll long long
#define eps 1e-6
#define maxi(a, b) ((a)>(b) ? (a):(b))
#define mini(a, b) ((a)<(b) ? (a):(b))
#define sqr(a) ((a)*(a))
int main()
{
    //freopen("in.txt", "r", stdin);
    char a[110], b[110], ina[110], fra[110], inb[110], frb[110];
    int len1, cas=1, len2, i, j, intg, frc;
    while(scanf("%s %s", a, b)!=EOF)
    {
        len1=strlen(a);
        len2=strlen(b);
        for(j=0, i=0;i<len1 && a[i]!='.';i++)
        {
            ina[j++]=a[i];
        }
        ina[j]='\0';

        for(j=0, i=i+1;i<len1;i++)
        {
            fra[j++]=a[i];
        }
        for(j=j-1;j>0&&fra[j]=='0';j--);
        fra[j+1]='\0';


        for(j=0, i=0;i<len2 && b[i]!='.';i++)
        {
            inb[j++]=b[i];
        }
        inb[j]='\0';

        for(j=0, i=i+1;i<len2;i++)
        {
            frb[j++]=b[i];
        }
        for(j=j-1;j>0 && frb[j]=='0';j--);
        frb[j+1]='\0';

        intg=strcmp(ina, inb);
        frc=strcmp(fra, frb);

        if(intg==0 && frc==0)
            printf("Case %d: Same\n", cas);
        else if(intg>0)
            printf("Case %d: Bigger\n", cas);
        else if(intg<0)
            printf("Case %d: Smaller\n", cas);
        else if(intg==0 && frc!=0)
        {
            if(frc>0)
                printf("Case %d: Bigger\n", cas);
            else if(frc<0)
                printf("Case %d: Smaller\n", cas);
        }
        cas++;
    }
    return 0;
}


