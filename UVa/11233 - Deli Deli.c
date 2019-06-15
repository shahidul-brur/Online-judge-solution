//Accepted
#include<stdio.h>
#include<string.h>
struct irreg{
char in[25];
char out[25];
};
int main()
{
    freopen("11233.txt", "r", stdin);
    int l,n,i,j,flag,len;
    struct irreg ir[25];
    char word[25];
    scanf("%d %d",&l,&n);
    for(i=1;i<=l;i++)
    {
        scanf("%s",&ir[i].in);
        scanf("%s",&ir[i].out);
    }
    for(i=1;i<=n;i++)
    {
        flag=0;
        scanf("%s",&word);
        for(j=1;j<=l;j++)
        {
            if(strcmp(word, ir[j].in)==0)
            {
                printf("%s\n",ir[j].out);
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            len=strlen(word);
            if(word[len-1]=='y' &&(word[len-2]!='a'&&word[len-2]!='e'&&word[len-2]!='i'&&word[len-2]!='o'&&word[len-2]!='u'))
            {
                word[len-1]='i';
                printf("%s",word);
                printf("es\n");
            }
            else if(word[len-1]=='o'||word[len-1]=='s'||word[len-1]=='x'||(word[len-1]=='h'&&word[len-2]=='c')||(word[len-1]=='h'&&word[len-2]=='s'))
            {
                printf("%s",word);
                printf("es\n");
            }
            else
            {
                printf("%s",word);
                printf("s\n");
            }
        }

    }
    return 0;
}
