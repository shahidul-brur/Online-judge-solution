//Accepted

#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    //freopen("11716.txt", "r", stdin);
    int t,len,i,j,root,flag;
    char txt[100050];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        flag=0;
        gets(txt);
        len=strlen(txt);
        root=sqrt(len);
        if(root*root==len)
            flag=1;
        if(flag==0)
            printf("INVALID\n");
        else{
        for(i=0;i<root;i++)
        {
            for(j=i;j<len;j+=root)
            {
                printf("%c",txt[j]);
            }
        }
        printf("\n");
        }
    }
    return 0;
}
