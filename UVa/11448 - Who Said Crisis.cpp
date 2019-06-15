//Accepted

#include<stdio.h>
#include<string.h>
#define MAX 15000
void rev(char *from, char *to)
{
    int i,len;
    len=strlen(from);
    for(i=0;i<len;i++)
        to[i]=from[len-1-i];
    to[i]='\0';
}
int sub(char *large, char *small,char *result)
{
    char L[MAX], S[MAX], R[MAX],temp[MAX];
    int diff, s,l,hold,i,j,sign=0;
    s=strlen(small);
    l=strlen(large);
    if(s>l)
    {
        strcpy(temp,small);
        strcpy(small,large);
        strcpy(large,temp);
        i=s;
        s=l;
        l=i;
        sign=1;
    }
    if(s==l)
    {
        if(strcmp(small,large)>0){
        strcpy(temp,small);
        strcpy(small,large);
        strcpy(large,temp);
        i=s;
        s=l;
        l=i;
        sign=1;
        }
    }
    rev(large,L);
    rev(small,S);
    for(i=s;i<l;i++)
        S[i]='0';
    S[i]='\0';
    hold=0;
    for(i=0;i<l;i++)
    {
        diff=L[i] - ( S[i] + hold );
        if(diff<0)
        {
            R[i]=10+diff+'0';
            hold=1;
        }
        else
        {
            R[i]=diff+'0';
            hold=0;
        }
    }
    for(i=l-1;i>0&&R[i]=='0';i--);
    R[i+1]='\0';
    rev(R,result);
    return sign;
}
int main()
{
    long t,len,i;
    char f[MAX],s[MAX],ans[MAX];
    scanf("%ld",&t);
    while(t-->0)
    {
        scanf("%s %s",&f,&s);
        if(sub(f,s,ans)==1)
            printf("-");
        len=strlen(ans);
        for(i=0;i<len;i++)
            printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
