//Accepted

#include<stdio.h>
#include<string.h>
struct excuse
{
    char key[25];
    char sen[75];
};
int main()
{
    freopen("409.txt", "r", stdin);
    int k,e,i,j,max,len,l,m,v[25],c=1;
    struct excuse list[25];
    char word[25];
    while(scanf("%d %d",&k,&e)!=EOF)
    {
        max=0;
        getchar();
        for(i=1;i<=k;i++)
        {
            gets(list[i].key);
        }
        for(i=1;i<=e;i++)
        {
            gets(list[i].sen);
        }
        for(i=1;i<=e;i++)
        {
            v[i]=0;
            len=strlen(list[i].sen);
            for(j=0;j<len;j++)
            {
                l=0;
                while((list[i].sen[j]>='a'&&list[i].sen[j]<='z') ||(list[i].sen[j]>='A'&&list[i].sen[j]<='Z'))
                {
                    if(list[i].sen[j]>='A'&&list[i].sen[j]<='Z')
                        word[l]=list[i].sen[j]+32;
                    else word[l]=list[i].sen[j];
                    l++;
                    j++;

                }
                word[l]='\0';
                for(m=1;m<=k;m++)
                {
                    if(strcmp(word, list[m].key)==0)
                    {
                        v[i]++;
                        break;
                    }
                }
            }
            if(v[i]>max)
                max=v[i];
        }
        printf("Excuse Set #%d\n",c);
        for(i=1;i<=e;i++)
            if(v[i]==max)
                puts(list[i].sen);
        printf("\n");
        c++;
    }
    return 0;
}
