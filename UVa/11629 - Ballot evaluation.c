#include<stdio.h>
#include<string.h>
struct election
{
    char name[25];
    int vote;
}party[53];
int main()
{
    freopen("11629.txt", "r", stdin);
    int p,g,i,j,k,L,R,cas,gL;
    char gess[1000], op[5], pName[25];
    float value;
    scanf("%d %d",&p,&g);
    for(i=1;i<=p;i++)
    {
        scanf("%s",&party[i].name);
        scanf("%f",&value);
        party[i].vote=(int)(double)(value*10+0.00001);
    }
    getchar();
    for(cas=1;cas<=g;cas++)
    {
        gets(gess);
        gL=strlen(gess);
        for(i=gL-1;gess[i]!=' ';i--);
        L=R=0;
        for(j=i+1;j<gL;j++)
            R=R*10 + (gess[j]-'0');
        R*=10;
        for(j=i-1;gess[j]!=' ';j--);
        gess[j]='\0';
        gL=strlen(gess);
        k=0;
        for(i=j+1;gess[i]!=' ';i++)
            op[k++]=gess[i];
        op[k]='\0';
        for(i=0;i<gL;i++)
        {
            k=0;
            for(j=i;gess[j]!=' ' && j<gL;j++)
            {
                pName[k++]=gess[j];
            }
            pName[k]='\0';
            i=j+2;
            for(j=1;j<=p;j++)
            {
                if(strcmp(party[j].name, pName)==0)
                {
                    L+=party[j].vote;
                    break;
                }
            }
        }

        if(strcmp(op, "<")==0)
        {
            if(L<R)
                printf("Guess #%d was correct.\n", cas);
            else
                printf("Guess #%d was incorrect.\n", cas);
        }
        else if(strcmp(op, ">")==0)
        {
            if(L>R)
                printf("Guess #%d was correct.\n", cas);
            else
                printf("Guess #%d was incorrect.\n", cas);
        }
        else if(strcmp(op, "=")==0)
        {
            if(L==R)
                printf("Guess #%d was correct.\n", cas);
            else
                printf("Guess #%d was incorrect.\n", cas);
        }
        else if(strcmp(op, ">=")==0)
        {
            if(L>=R)
                printf("Guess #%d was correct.\n", cas);
            else
                printf("Guess #%d was incorrect.\n", cas);
        }
        else if(strcmp(op, "<=")==0)
        {
            if(L<=R)
                printf("Guess #%d was correct.\n", cas);
            else
                printf("Guess #%d was incorrect.\n", cas);
        }
    }
     return 0;
}
