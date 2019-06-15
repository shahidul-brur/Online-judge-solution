//Accepted
#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10361.txt", "r", stdin);
    char line1[500],line2[500],s2[500]={},s3[500]={},s4[500]={},s5[500]={};
    int i,j,len,t,k,l,m,n;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(line1);
        gets(line2);
        i=0;
        while(line1[i]!='<')
        {
            i++;
        }
        i++;
         j=0;
         while(line1[i]!='>')
         {
             s2[j]=line1[i];
             i++;
             j++;
         }
         s2[j]='\0';
        i++;
        j=0;
        while(line1[i]!='<')
         {
             s3[j]=line1[i];
             i++;
             j++;
         }
         s3[j]='\0';
        i++;
        j=0;
        while(line1[i]!='>')
         {
             s4[j]=line1[i];
             i++;
             j++;
         }
         s4[j]='\0';
        i++;
        j=0;
        while(line1[i]!='\0')
         {
             s5[j]=line1[i];
             i++;
             j++;
         }
         s5[j]='\0';
         for(i=0;line1[i]!='\0';i++)
         {
             if(line1[i]!='<' && line1[i]!='>')
                printf("%c",line1[i]);
         }
         printf("\n");
         i=0;
         while(line2[i]!='.')
         {
             printf("%c",line2[i]);
             i++;
         }
         printf("%s%s%s%s",s4,s3,s2,s5);
         printf("\n");

    }
    return 0;
}
