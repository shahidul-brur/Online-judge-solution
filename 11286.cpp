#include <stdio.h>

struct strct
{
    int popu=1, c1, c2, c3, c4, c5, counted=0;
}student[10001];

int same(int a, int b)
{
    int match=0;
    if(student[a].c1==student[b].c1 || student[a].c1==student[b].c2  || student[a].c1==student[b].c3  || student[a].c1==student[b].c4  || student[a].c1==student[b].c5)
        match++;
    if(student[a].c2==student[b].c1 || student[a].c2==student[b].c2  || student[a].c2==student[b].c3  || student[a].c2==student[b].c4  || student[a].c2==student[b].c5)
        match++;
    if(student[a].c3==student[b].c1 || student[a].c3==student[b].c2  || student[a].c3==student[b].c3  || student[a].c3==student[b].c4  || student[a].c3==student[b].c5)
        match++;
    if(student[a].c4==student[b].c1 || student[a].c4==student[b].c2  || student[a].c4==student[b].c3  || student[a].c4==student[b].c4  || student[a].c4==student[b].c5)
        match++;
    if(student[a].c5==student[b].c1 || student[a].c5==student[b].c2  || student[a].c5==student[b].c3  || student[a].c5==student[b].c4  || student[a].c5==student[b].c5)
        match++;
    if(match==5)
        return 1;
    else return 0;
}

int main()
{
    freopen("11286.txt", "r", stdin);
    int n, i, j, cnt, maxi, similar[10001], s, ans;
    while(scanf("%d", &n)!=EOF)
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d %d", &student[i].c1, &student[i].c2, &student[i].c3, &student[i].c4, &student[i].c5);
            student[i].counted=0;
            student[i].popu=1;
        }

        maxi=0;
        for(i=0;i<n;i++)
        {
            if(student[i].counted==0)
            {
                cnt=1;
                s=0;
                similar[s++]=i;
                student[i].counted=1;
                for(j=i+1;j<n;j++)
                {
                    if(student[j].counted==0)
                    {
                        if(same(i, j)==1)
                        {
                            cnt++;
                            similar[s++]=j;
                            student[j].counted=1;
                        }
                    }
                }
                //for(j=0;j<s;j++)
                    //student[similar[j]].popu=cnt;
                if(cnt>maxi)
                {
                    maxi=cnt;
                    ans=s;
                }
                else if(cnt==maxi)
                    ans++;
            }
        }
        /*
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(student[i].popu==maxi)
                cnt++;
        }
        */
        printf("%d\n", ans);
    }
    return 0;
}
