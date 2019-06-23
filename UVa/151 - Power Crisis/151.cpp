#include <stdio.h>

int main()
{
    int i, last, j, n, m, p[100],cnt, lp;
    while(scanf("%d",&n)&&n!=0)
    {
        for(i=1;i<=n;i++)
            p[i]=i;
        last=1;
        for(m=2;;m++)
        {
            cnt=0;
            j=1;
            while(cnt<n)
            {
                last=p[j];
                p[j]=-1;
                cnt++;
                lp=0;
                if(cnt==n)
                    break;
                for(i=j+m;lp<m;i++)
                {
                    if(i>n)
                        i=1;
                    if(p[i]!=-1)
                        lp++;
                }
                j=i-1;
            }
            printf("%d\n",last);
            if(last==n)
                break;
        }
        printf("\nm=%d\n",m);
    }
    return 0;
}
