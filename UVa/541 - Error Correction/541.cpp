//Accepted

#include <stdio.h>
int main()
{
    freopen("541.txt", "r", stdin);
    int n, mat[101][101], r[101], i, j, c[101], oddR, oddC, ch1, ch2;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;

        for(i=1;i<=n;i++)
        {
            r[i]=0;
            c[i]=0;
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d", &mat[i][j]);
                r[i]+=mat[i][j];
                c[j]+=mat[i][j];
            }
        }

        oddR=oddC=0;

        for(i=1;i<=n;i++)
        {
            if(r[i]%2!=0)
            {
                ch1=i;
                oddR++;
            }
            if(c[i]%2!=0)
            {
                ch2=i;
                oddC++;
            }
        }
        if(oddR==0 && oddC==0)
            printf("OK\n");
        else if(oddR==1 && oddC==1)
            printf("Change bit (%d,%d)\n", ch1, ch2);
        else
            printf("Corrupt\n");
    }
    return 0;
}
