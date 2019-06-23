//Accepted
#include <stdio.h>
#include <string.h>
int main()
{
    freopen("119.txt", "r", stdin);
    int n, i, j, earn[12], give, person, k, cas=1;
    char name[12][14], to[14], who[14];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%s", &name[i]);
        for(i=0;i<n;i++)
            earn[i]=0;
        for(i=0;i<n;i++)
        {
            scanf("%s %d %d ", &who, &give, &person);
            if(give>0)
            {
                for(j=0;j<n;j++)
                {
                    if(strcmp(who, name[j])==0)
                    {
                        earn[j]=earn[j] - give;
                        if(person>0)
                           earn[j]=earn[j] + give%person;
                        else
                            earn[j]=earn[j] + give;
                        break;
                    }
                }
            }
            if(person>0)
            {
                for(j=0;j<person;j++)
                {
                    scanf("%s", &to);
                    if(give/person > 0)
                     {
                         for(k=0;k<n;k++)
                        {
                            if(strcmp(to, name[k])==0)
                            {
                                earn[k]=earn[k] + give/person;
                                break;
                            }
                        }
                     }
                }
            }
        }

        if(cas>1)
            printf("\n");
        for(i=0;i<n;i++)
            printf("%s %d\n", name[i], earn[i]);
        cas++;
    }
    return 0;
}
