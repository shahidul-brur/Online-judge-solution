//Accepted

#include<stdio.h>
#include<string.h>
struct guest
{
    char song[20];
    char name[110];
};
int main()
{
    freopen("12554.txt", "r", stdin);
    int n,i,j,k,t;
    struct guest word[20];
    struct guest gest[110];
    strcpy(word[1].song, "Happy");
    strcpy(word[2].song, "birthday");
    strcpy(word[3].song, "to");
    strcpy(word[4].song, "you");
    strcpy(word[5].song, "Happy");
    strcpy(word[6].song, "birthday");
    strcpy(word[7].song, "to");
    strcpy(word[8].song, "you");
    strcpy(word[9].song, "Happy");
    strcpy(word[10].song, "birthday");
    strcpy(word[11].song, "to");
    strcpy(word[12].song, "Rujia");
    strcpy(word[13].song, "Happy");
    strcpy(word[14].song, "birthday");
    strcpy(word[15].song, "to");
    strcpy(word[16].song, "you");

    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%s",&gest[i].name);
    if(n<=16)
    {
        for(i=1,j=1;i<=16;i++,j++)
        {
            printf("%s: %s\n",gest[j].name,word[i].song);
            if(j==n)
                j=0;
        }
    }
    else
    {
        t=n/16+1;
        for(i=1,j=1,k=1;i<=t*16;i++,j++,k++)
        {
            printf("%s: %s\n",gest[j].name,word[k].song);
            if(j==n)
                j=0;
            if(k==16)
                k=0;
        }
    }
    return 0;
}
