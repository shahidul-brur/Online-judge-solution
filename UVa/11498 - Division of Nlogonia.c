//Accepted

#include<stdio.h>
int main()
{
    //freopen("11498.txt", "r", stdin);
    int t,i,cx,cy,x,y;
    while(scanf("%d",&t) && t!=0)
    {
        scanf("%d %d",&cx,&cy);
        for(i=0;i<t;i++)
        {
            scanf("%d %d",&x,&y);
            if(x==cx || y==cy)
                printf("divisa\n");
            else if(x>cx && y>cy)
                printf("NE\n");
            else if(x>cx && y<cy)
                printf("SE\n");
            else if(x<cx && y>cy)
                printf("NO\n");
            else if(x<cx && y<cy)
                printf("SO\n");
        }
    }
    return 0;
}
