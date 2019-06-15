//Accepted
#include<stdio.h>
struct symbole{
char ch[110];
};
int main()
{
    int m,n,i,j,count,c=1;
    struct symbole in[105];
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
           break;
        for(i=0;i<n;i++)
            scanf("%s",&in[i].ch);
        if(c>1)
            printf("\n");
        printf("Field #%d:\n",c);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++){

            if(in[i].ch[j]=='.')
            {
               count=0;
               if(j!=m-1){
               if(in[i].ch[j+1]=='*')
                    count++;
               }
            if(j>0){
               if(in[i].ch[j-1]=='*')
                    count++;
                }
                if(i>0){
               if(in[i-1].ch[j]=='*')
                    count++;
                }
                if(i!=n-1){
               if(in[i+1].ch[j]=='*')
                    count++;
                }
                if(i>0 && j!=m-1){
               if(in[i-1].ch[j+1]=='*')
                    count++;
                }
                if(i>0 && j>0){
                if(in[i-1].ch[j-1]=='*')
                    count++;
                }
                if(i!=n-1 && j!=m-1){
               if(in[i+1].ch[j+1]=='*')
                    count++;
                }
                if(j>0 && i!=n-1){
               if(in[i+1].ch[j-1]=='*')
                    count++;
                }
                printf("%d",count);
            }
            else
                printf("%c",in[i].ch[j]);
            }
            printf("\n");
        }
        c++;
    }
    return 0;
}
