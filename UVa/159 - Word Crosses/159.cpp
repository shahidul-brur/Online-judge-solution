//Accepted

#include <stdio.h>
#include <string.h>

int main()
{
    //freopen("159.txt", "r", stdin);
    int cas=1, c1, c2, c3, c4, len1, len2, len3, len4, i, j, maxi, mS1, mS2, mS3, mS4, match1, match2, mini;
    char s1[12], s2[12], s3[12], s4[12];
    while(scanf("%s", s1)!=EOF)
    {
        if(s1[0]=='#')
            break;
        scanf("%s %s %s", s2, s3, s4);
        len1=strlen(s1);
        len2=strlen(s2);
        len3=strlen(s3);
        len4=strlen(s4);
        match1=match2=0;
        for(i=0;i<len1;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(s2[j]==s1[i])
                {
                    mS1=i;
                    mS2=j;
                    match1=1;
                    break;
                }
            }
            if(match1==1)
                break;
        }

        for(i=0;i<len3;i++)
        {
            for(j=0;j<len4;j++)
            {
                if(s4[j]==s3[i])
                {
                    mS3=i;
                    mS4=j;
                    match2=1;
                    break;
                }
            }
            if(match2==1)
                break;
        }

        if(cas>1)
            printf("\n");
        if(match1==0 || match2==0)
            printf("Unable to make two crosses\n");
        else
        {
            c1=c2=c3=c4=0;
            if(mS2>mS4)
            {
                maxi=mS2;
                mini=mS4;
            }
            else
            {
                maxi=mS4;
                mini=mS2;
            }

            if(maxi==mS2)
                for(i=0;i<(maxi-mini);i++)
                {
                    for(j=0;j<mS1;j++)
                        printf(" ");
                    printf("%c\n", s2[c2++]);
                }
            else
                for(i=0;i<(maxi-mini);i++)
                {
                    for(j=0;j<len1+3+mS3;j++)
                        printf(" ");
                    printf("%c\n", s4[c4++]);
                }

            for(i=0;i<mini;i++)
            {
                for(j=0;j<mS1;j++)
                    printf(" ");
                printf("%c", s2[c2++]);

                for(j=0;j<((len1-mS1-1)+3+mS3);j++)
                    printf(" ");
                printf("%c\n", s4[c4++]);
            }

            printf("%s   %s\n", s1, s3);

            c2++;
            c4++;
            while(c2<len2 && c4<len4)
            {
                for(j=0;j<mS1;j++)
                    printf(" ");
                printf("%c", s2[c2++]);

                for(j=0;j<((len1-mS1-1)+3+mS3);j++)
                    printf(" ");
                printf("%c\n", s4[c4++]);
            }

            while(c2<len2)
            {
                for(j=0;j<mS1;j++)
                    printf(" ");
                printf("%c\n", s2[c2++]);
            }

            while(c4<len4)
            {
                for(j=0;j<len1+3+mS3;j++)
                    printf(" ");
                printf("%c\n", s4[c4++]);
            }
        }
        cas++;
    }
    return 0;
}
