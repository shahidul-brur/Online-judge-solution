#include<stdio.h>
#include<string.h>
struct frq
{
    char ch;
    int v;
};
int main()
{
    freopen("10008.txt", "r", stdin);
    int n,i,j,let[28], out[28],temp,c;
    char k,str[99999];
    struct frq alfa[28];
    for(i=0;i<26;i++)
        let[i]=0;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        gets(str);
        for(i=j=0;str[i]!='\0';i++)
        {
            if(str[i]>='a' && str[i<='z'])
                str[j++]=str[i]-32;
            else if(str[i]>='A' && str[i]<='Z')
                str[j++]=str[i];
        }
          str[j]='\0';
        for(i=0;i<j;i++)
        {
            k=str[i]-'A';
            let[k]++;
        }
    }
    j=0;
    for(i=0;i<26;i++)
    {
        if(let[i]>0)
        {
            alfa[j].ch=i+'A';
            alfa[j].v=let[i];
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        for(k=0;k<j-1;k++)
        {
            if(alfa[k].v<alfa[k+1].v)
            {
                c=alfa[k].ch;
                alfa[k].ch=alfa[k+1].ch;
                alfa[k+1].ch=c;
                temp=alfa[k].v;
                alfa[k].v=alfa[k+1].v;
                alfa[k+1].v=temp;
            }
        }
    }
    for(i=0;i<j;i++)
    {
        printf("%c %d\n",alfa[i].ch,alfa[i].v);
    }
    return 0;

}
