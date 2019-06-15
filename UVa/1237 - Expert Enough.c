    //Accepted

    #include<stdio.h>
    #include<string.h>
    int main()
    {
        //freopen("1237.txt", "r", stdin);
        long long int t, d, q,l[10010],h[10010],i,j,end[10010],src,k,start[10010],found,f,m;
        char maker[25],mixed[200000];
        scanf("%lld",&t);
        for(m=1;m<=t;m++)
        {
            k=0;
            scanf("%lld",&d);
            for(i=0;i<d;i++)
            {
                scanf("%s",&maker);
                start[i]=k;
                end[i]=k+strlen(maker)-1;
                for(j=0;j<strlen(maker);j++)
                {
                    mixed[k]=maker[j];
                    k++;
                }
                scanf("%lld",&l[i]);
                scanf("%lld",&h[i]);
            }
            scanf("%lld",&q);
            while(q--)
            {
                found=0;
                scanf("%lld",&src);
                for(i=0;i<d;i++)
                {
                  if(src>=l[i] && src<=h[i])
                  {
                    found++;
                    f=i;
                  }
                }
                if(found==1)
                {
                    for(j=start[f];j<=end[f];j++)
                    {
                        printf("%c",mixed[j]);
                    }
                    printf("\n");
                    found=0;
                }
                else printf("UNDETERMINED\n");
            }
           if(m!=t)
               puts("");

        }
        return 0;
    }

