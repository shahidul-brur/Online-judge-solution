#include<stdio.h>
#include<string.h>
int vow(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return 1;
    return 0;
}
int main()
{
    //freopen("11713.txt", "r", stdin);
    int t,i,yes,v,len1,len2;
    char name1[25],name2[25];
    scanf("%d",&t);
    while(t--)
    {
        yes=1;
        scanf("%s",&name1);
        scanf("%s",&name2);
        len1=strlen(name1);
        len2=strlen(name2);
        if(len1!=len2)
            yes=0;
        else
        {
            for(i=0;i<len1;i++)
            {
                if(vow(name1[i])!=vow(name2[i]))
                 {
                     yes=0;
                     break;
                 }
                 else if(vow(name1[i])==0 && vow(name2[i])==0)
                {
                    if(name1[i]!=name2[i])
                    {
                        yes=0;
                        break;
                    }
                }
            }
        }
        if(yes==1)
                printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
