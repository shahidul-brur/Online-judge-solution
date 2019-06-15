#include <stdio.h>
#include <string.h>
int main()
{
    freopen("10761.txt", "r", stdin);
    int cnt, cas=1, i, len1, j, letter[27], brk, len2, c, cndg, csdg, b;
    char txt[100], broken[100], ch;
    printf("+----------+----------------+-----------------------------+\n");
    printf("| Keyboard | # of printable | Additionally, the following |\n");
    printf("|          |      lines     |  letter keys can be broken  |\n");
    printf("+----------+----------------+-----------------------------+\n");
    while(gets(broken))
    {
        if(strcmp(broken, "finish")==0)
            break;
        for(i=0;i<26;i++)
            letter[i]=0;
        len1=strlen(broken);
        for(i=0;i<len1;i++)
        {
            ch=broken[i];
            if(ch>='A' && ch<='Z')
                ch=ch-'A'+'a';
            letter[ch-'a']=1;
            broken[i]=ch;
        }
        cnt=0;

        while(gets(txt))
        {
            brk=0;
            len2=strlen(txt);
            for(i=0;i<len2;i++)
            {
                b=1;
                ch=txt[i];
                if(ch>='A' && ch<='Z')
                    ch=ch-'A'+'a';
                if(ch>='a' && ch<='z')
                {
                    for(j=0;j<len1;j++)
                        if(ch==broken[j])
                        {
                            b=0;
                            break;
                        }
                        if(b==0)
                            brk=1;
                }
            }
            if(brk==0)
            {
                cnt++;
                for(i=0;i<len2;i++)
                {
                    ch=txt[i];
                    if(ch>='A' && ch<='Z')
                        ch=ch-'A'+'a';
                    if(ch>='a' && ch<='z')
                    {
                        letter[ch-'a']=1;
                    }
                }
            }
            if(strcmp(txt, "END")==0)
                break;

        }
        if(cas<10)
            csdg=1;
        else if(cas>9 && cas<100)
            csdg=2;
        else if(cas>99)
            csdg=3;
        if(cnt<10)
            cndg=1;
        else if(cnt>9 && cnt<100)
            cndg=2;
        else if(cnt>99)
            cndg=3;
        printf("|");
        for(i=1;i<=6-csdg;i++)
            printf(" ");
        printf("%d",cas);
        printf("    |");
        for(i=1;i<=9-cndg;i++)
            printf(" ");
        printf("%d",cnt);
        printf("       | ");
        c=0;
        for(i=0;i<26;i++)
        {
            if(letter[i]==0)
            {
                c++;
                printf("%c",'a'+i);
            }
        }
        c=28-c;
        for(i=1;i<=c;i++)
            printf(" ");
        printf("|\n");
        printf("+----------+----------------+-----------------------------+\n");
        cas++;

    }
    return 0;
}
