#include<stdio.h>
int main()
{
    freopen("10363.txt", "r", stdin);
    char L1[5],L2[5],L3[5];
    int n,i,x,o;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",&L1);
        scanf("%s",&L2);
        scanf("%s",&L3);
        x=o=0;
        for(i=0;i<3;i++)
          {
             if(L1[i]=='X')
                x++;
             else if(L1[i]=='O')
                o++;
          }
        for(i=0;i<3;i++)
          {
             if(L2[i]=='X')
                x++;
             else if(L2[i]=='O')
                o++;
          }
        for(i=0;i<3;i++)
          {
             if(L3[i]=='X')
                x++;
             else if(L3[i]=='O')
                o++;
          }
          if(x==o || x==(o+1))
                printf("yes\n");
          else printf("no\n");

    }
    return 0;
}
