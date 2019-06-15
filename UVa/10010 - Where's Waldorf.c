//Accepted

#include<stdio.h>
#include<string.h>
int main()
{
    freopen("10010.txt", "r", stdin);
    int cas,t,ck,n,m,i,j,k,l,match,len,R,C,p;
    char word[60], grid[60][60];
    scanf("%d\n",&t);
    for(cas=1;cas<=t;cas++)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++)
        {
            scanf("%s",&grid[i]);
            for(j=0;j<n;j++)
            {
                if(grid[i][j]<'a')
                    grid[i][j]+=32;
            }
        }
        scanf("%d",&ck);
        while(ck--)
        {
            scanf("%s",&word);
            len=strlen(word);
            for(i=0;i<len;i++)
            {
                if(word[i]<'a')
                    word[i]+=32;
            }
            match=0;
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {

                    if(n-j>=len)
                    {
                        match=1;
                        for(l=0,k=j;k<=j+len-1;k++)
                        {
                            if(grid[i][k]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }

                    }

                    if(j+1>=len)
                    {
                        match=1;
                        for(l=0,k=j;k>=j-len+1;k--)
                        {
                            if(grid[i][k]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }
                    }

                    if(m-i>=len)
                    {
                        match=1;
                        for(l=0,k=i;k<=i+len-1;k++)
                        {
                            if(grid[k][j]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }

                    }

                    if(i+1>=len)
                    {
                        match=1;
                        for(l=0,k=i;k>=i-len+1;k--)
                        {
                            if(grid[k][j]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }
                    }

                    if(n-j>=len && m-i>=len)
                    {
                        match=1;
                        for(l=0,p=i,k=j;k<=j+len-1;p++,k++)
                        {
                            if(grid[p][k]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }

                    }

                    if(j+1>=len && i+1>=len)
                    {
                        match=1;
                        for(l=0,p=i,k=j;k>=j-len+1;p--,k--)
                        {
                            if(grid[p][k]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }
                    }


                    if(n-j>=len && j+1>=len)
                    {
                        match=1;
                        for(l=0,p=i,k=j;k>=j-len+1;p++,k--)
                        {
                            if(grid[p][k]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }

                    }

                    if(j+1>=len && i+1>=len)
                    {
                        match=1;
                        for(l=0,p=i,k=j;k<=j+len-1;p--,k++)
                        {
                            if(grid[p][k]!=word[l])
                            {
                                match=0;
                                break;
                            }
                            l++;
                        }
                        if(match==1)
                        {
                            R=i+1;
                            C=j+1;
                            break;
                        }
                    }

                }
                if(match==1)
                    break;

            }
            printf("%d %d\n",R,C);
        }
        if(cas<t)
            printf("\n");
    }
    return 0;
}
