//Accepted
#include <stdio.h>

int main()
{
    //freopen("612.txt", "r", stdin);
    int t, c=1, n, m, i, j, k, order[110], sum, tmp, tm, lst[110];
    char dna[110][60];
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            lst[i]=i;
            sum=0;
            scanf("%s",&dna[i]);
            for(j=0;j<n-1;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    if(dna[i][j]>dna[i][k])
                        sum++;
                }
            }
            order[i]=sum;

        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m-1;j++)
            {
                if(order[j]>order[j+1])
                {
                    tm=order[j];
                    order[j]=order[j+1];
                    order[j+1]=tm;
                    tmp=lst[j];
                    lst[j]=lst[j+1];
                    lst[j+1]=tmp;
                }
            }
        }
        if(c>1)
            printf("\n");
        for(i=0;i<m;i++)
        {

            printf("%s\n",dna[lst[i]]);
        }
        c++;
    }
    return 0;
}
