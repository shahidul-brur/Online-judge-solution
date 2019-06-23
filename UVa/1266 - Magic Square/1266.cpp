#include <stdio.h>
#include <string.h>
int main()
{
    freopen("1266.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, i, cas=1, j, r, c, value, square[230][230], right, dm, d, sum, k;
    while(scanf("%d", &n)!=EOF)
    {
        memset(square, 0, sizeof(square));
        r=0;
        c=n/2;
        dm=0;
        k=n*n;
        while(k>0)
        {
            k/=10;
            dm++;
        }

        for(value=1;value<=n*n;)
        {
            square[r][c]=value;

            r--;
            c++;
            value++;
            right=0;
            while(right==0)
            {
                if(value>n*n)
                    break;
                if(r>=n)
                    r-=n;
                else if(r<0)
                    r+=n;

                if(c>=n)
                    c-=n;
                else if(c<0)
                    c+=n;

                if(square[r][c]==0)
                    right=1;
                else
                {
                    r+=2;
                    c--;
                }
            }
        }
        sum=0;
        for(i=0;i<n;i++)
            sum+=square[0][i];
        if(cas>1)
            printf("\n");
        printf("n=%d, sum=%d\n", n, sum);
        dm=0;
        k=n*n;
        while(k>0)
        {
            k/=10;
            dm++;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                d=0;
                k=square[i][j];
                while(k>0)
                {
                    k/=10;
                    d++;
                }
                printf(" ");
                for(k=1;k<=(dm-d);k++)
                    printf(" ");
                printf("%d", square[i][j]);
            }
            printf("\n");
        }
        cas++;
    }
    return 0;
}
