//Accepted

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct card
{
  char  output[15][4];
  int cnt;
}person[5];


int cmp(char f[], char s[])
{
    if(f[0]==s[0])
    {
        if(f[1]==s[1])
                return 0;
        else if((f[1]>='2' && f[1]<='9') && (s[1]>='2' && s[1]<='9'))
        {
            if(f[1]>s[1])
                return 1;
            else return 0;
        }
        else if(f[1]>'9' && (s[1]>='2' && s[1]<='9'))
            return 1;
        else if(s[1]>'9' && (f[1]>='2' && f[1]<='9'))
            return 0;
        else if(f[1]>'9' && s[1]>'9')
        {
            if(f[1]=='A')
                return 1;
            else if(f[1]=='K' && (s[1]!='A'))
                return 1;
            else if(f[1]=='Q' && (s[1]=='J' || s[1]=='T'))
                return 1;
            else if(f[1]=='J' && s[1]=='T')
                return 1;
            else return 0;
        }
    }
    else
    {
        if(f[0]=='H')
            return 1;
        else if(f[0]=='S' && s[0]!='H')
            return 1;
        else if(f[0]=='D' && s[0]=='C')
            return 1;
        else return 0;
    }
}

int main()
{
    freopen("555.txt", "r", stdin);
    int i, j, start, k;
    char first[60], second[60], sq[5], temp[5], p[6];
    strcpy(p, " SWNE");
    while(scanf("%s", &sq)!=EOF)
    {
        if(strcmp(sq, "#")==0)
            break;

        for(i=1;i<=4;i++)
            person[i].cnt=0;
        scanf("%s", &first);
        scanf("%s", &second);

        if(sq[0]=='E')
            start=1;
        else if(sq[0]=='S')
            start=2;
        else if(sq[0]=='W')
            start=3;
        else if(sq[0]=='N')
            start=4;

        for(i=0;i<51;i+=2)
        {
            person[start].output[person[start].cnt][0]=first[i];
            person[start].output[person[start].cnt][1]=first[i+1];
            person[start].output[person[start].cnt][2]='\0';
            person[start].cnt++;
            start++;
            if(start==5)
                start=1;
        }

        for(i=0;i<51;i+=2)
        {
            person[start].output[person[start].cnt][0]=second[i];
            person[start].output[person[start].cnt][1]=second[i+1];
            person[start].output[person[start].cnt][2]='\0';
            person[start].cnt++;
            start++;
            if(start==5)
                start=1;
        }


        for(i=1;i<=4;i++)
        {
            for(j=0;j<person[i].cnt;j++)
            {
                for(k=0;k<(person[i].cnt-1);k++)
                {
                    if(cmp(person[i].output[k], person[i].output[k+1])==1)
                    {
                        strcpy(temp, person[i].output[k]);
                        strcpy(person[i].output[k], person[i].output[k+1]);
                        strcpy(person[i].output[k+1], temp);
                    }
                }
            }
        }

        for(i=1;i<=4;i++)
        {
            printf("%c: ", p[i]);
            for(j=0;j<person[i].cnt;j++)
            {
                if(j>0)
                    printf(" ");
                printf("%s", person[i].output[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
