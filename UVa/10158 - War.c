#include<stdio.h>
int main()
{
    freopen("10158.txt", "r", stdin);
    int n, relation, frend[10010], enemy[10010], m1,m2,i=0,j=0,k,l,f1,f2,e1,e2;
    scanf("%d",&n);
    while(scanf("%d %d %d",&relation,&m1,&m2)&&(relation!=0 || m1!=0 || m2!=0))
    {
        f1=f2=e1=e2=0;
        if(relation==1)
        {
            frend[i]=m1;
            frend[i+1]=m2;
            i+=2;
        }
        else if(relation==2)
        {
            enemy[j]=m1;
            enemy[j+1]=m2;
            j+=2;
        }
        if(relation==3)
        {
            for(k=0;k<i;k++)
            {
                if(m1==frend[k])
                {
                    f1=1;
                    break;
                }
                //printf("%d\n",frend[k]);
            }
            for(k=0;k<i;k++)
            {
                if(m2==frend[k])
                {
                    f2=1;
                    break;
                }
            }
        }
        if(relation==4)
        {
            for(k=0;k<j;k++)
            {
                if(m1==enemy[k])
                {
                    e1=1;
                    break;
                }

                //printf("%d\n",enemy[k]);
            }
            for(k=0;k<j;k++)
            {
                if(m2==enemy[k])
                {
                    e2=1;
                    break;
                }
            }
            if((f1==1 || f2==1) && (e1==1 || e2==1))
                printf("-1\n");
            else if(e1==1 && e2==1)
                printf("1\n");
            else if(f1==1 && f2==0)
                printf("0\n");
        }

        //printf("Relation= %d Friends = %d %d ",relation,frend[i-2],frend[i-1]);
        //printf("Enemies = %d %d ; i=%d, j=%d\n",enemy[j-2],enemy[j-1],i,j);
    }
    return 0;
}
