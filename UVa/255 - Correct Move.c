//Accepted

#include<stdio.h>
int main()
{
    freopen("255.txt", "r",stdin);
    int board[10][10], leg[20],legal,allow;
    int k,q,m,i,j,l,flag,p=0,kr,kc,qr,qc,mr,mc;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            board[i][j]=p;
            p++;
        }
    }
    while(scanf("%d %d %d",&k,&q,&m)!=EOF)
    {
        if(k==q)
            printf("Illegal state\n");
        else
        {
            kr=k/8;
            kc=k-kr*8;
            qr=q/8;
            qc=q-qr*8;
            mr=m/8;
            mc=m-mr*8;

            l=1;
            for(i=qc+1;i<8;i++)
            {
                if(qr==kr && i==kc)
                    break;
                leg[l]=board[qr][i];
                l++;
            }
            for(i=qc-1;i>=0;i--)
            {
                if(qr==kr && i==kc)
                    break;
                leg[l]=board[qr][i];
                l++;

            }
            for(i=qr+1;i<8;i++)
            {
                if(qc==kc && i==kr)
                    break;
                leg[l]=board[i][qc];
                l++;
            }
            for(i=qr-1;i>=0;i--)
            {
                if(qc==kc && i==kr)
                    break;
                leg[l]=board[i][qc];
                l++;
            }
            legal=0;
            for(i=1;i<l;i++)
            {
                if(m==leg[i])
                {
                    legal=1;
                    break;
                }
            }
            if(legal==0)
                printf("Illegal move\n");
            else
            {
                allow=1;
                if(kc<7)
                {
                    if(mr==kr && mc==kc+1)
                        allow=0;
                }
                if(kc>0)
                {
                    if(mr==kr && mc==kc-1)
                        allow=0;
                }
                if(kr>0)
                {
                    if(mr==kr-1 && mc==kc)
                        allow=0;
                }
                if(kr<7)
                {
                    if(mr==kr+1 && mc==kc)
                        allow=0;
                }
                if(allow==0)
                    printf("Move not allowed\n");
                else if((k==0 && m==9)||(k==7&&m==14)||(k==56&&m==49)||(k==63&&m==54))
                    printf("Stop\n");
                else printf("Continue\n");

        }
    }
    }
    return 0;
}
