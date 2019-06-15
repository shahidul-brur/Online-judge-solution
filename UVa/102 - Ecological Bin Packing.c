//Accepted

#include<stdio.h>
int main()
{
    int b[5],g[5],c[5],min,bcg,bgc,cbg,cgb,gbc,gcb;
    char set[3];
    while(scanf("%d %d %d %d %d %d %d %d %d",&b[1],&g[1],&c[1],&b[2],&g[2],&c[2],&b[3],&g[3],&c[3])!=EOF)
    {
        bcg=b[2]+b[3]+c[1]+c[3]+g[1]+g[2];
        bgc=b[2]+b[3]+c[1]+c[2]+g[1]+g[3];
        cbg=b[1]+b[3]+c[2]+c[3]+g[1]+g[2];
        cgb=b[1]+b[2]+c[2]+c[3]+g[1]+g[3];
        gbc=b[1]+b[3]+c[1]+c[2]+g[2]+g[3];
        gcb=b[1]+b[2]+c[1]+c[3]+g[2]+g[3];
        min=bcg;
        set[0]='B';
        set[1]='C';
        set[2]='G';
        if(bgc<min)
        {
            min=bgc;
            set[0]='B';
            set[1]='G';
            set[2]='C';
        }
        if(cbg<min)
        {
            min=cbg;
            set[0]='C';
            set[1]='B';
            set[2]='G';
        }
        if(cgb<min)
        {
            min=cgb;
            set[0]='C';
            set[1]='G';
            set[2]='B';
        }
        if(gbc<min)
        {
            min=gbc;
            set[0]='G';
            set[1]='B';
            set[2]='C';
        }
        if(gcb<min)
        {
            min=gcb;
            set[0]='G';
            set[1]='C';
            set[2]='B';
        }
        printf("%c%c%c %d\n",set[0],set[1],set[2],min);
    }
    return 0;
}
